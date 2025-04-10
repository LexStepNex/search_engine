#include "search_server.h"

#include <map>
#include <algorithm>

#include "functions_for_search_server.h"

SearchServer::SearchServer(InvertedIndex &idx) : _index(idx) {}

std::vector<std::vector<RelativeIndex>> SearchServer::search(const std::vector<std::string> &queries_input) {
    if (queries_input.empty()) return {};

    std::vector<std::multimap<int, std::string>> sort_requests;
    {
        //формируем только уникальные слова в каждом из запросов
        std::vector<std::map<std::string, int>> words_in_queries;
        for (const auto &request: queries_input) {
            words_in_queries.push_back(getUniqueWords(request));
        }
        //подсчёт слов для каждого запроса
        addWordCount(words_in_queries);

        //сортируем по возрастанию популярности
        sort_requests = swapCountWithWord(words_in_queries);
    }
    //Расчёта абсолютной релевантности для всех запросов и внутри него для всех документов
    auto absolute_relevance = calculationAbsoluteRelevances(sort_requests);

    //расчёт и вовзращение относительной релевантности
    return calculationRelativeRelevances(absolute_relevance);
}

void SearchServer::addWordCount(std::vector<std::map<std::string, int>> &words_in_queries) {
    for (auto &words_in_request: words_in_queries) {
        for (auto &word_count: words_in_request) {
            auto count_word_in_docs = _index.GetWordCount(word_count.first);

            if (!count_word_in_docs.empty()) {
                for (auto doc: count_word_in_docs) {
                    word_count.second += (int) doc.count;
                }
            }
        }
    }
}

std::vector<std::vector<int>>
SearchServer::calculationAbsoluteRelevances(const std::vector<std::multimap<int, std::string>> &sort_requests) {
    //количество запросов и документов
    size_t size_request = sort_requests.size();
    size_t size_doc = _index.getSizeDocs();

    std::vector<std::vector<int>> absolute_relevance(size_request, std::vector<int>(size_doc, 0));

    for (int i = 0; i < size_request; i++) {
        if (sort_requests[i].empty()) {
            absolute_relevance[i].clear();
            continue;
        }

        bool valid_request = false;
        for (const auto &request: sort_requests[i]) {
            auto docs_entry = _index.GetWordCount(request.second);
            if (!docs_entry.empty()) {
                valid_request = true;
                for (auto doc: docs_entry) {
                    absolute_relevance[i][doc.doc_id] += (int) doc.count;
                }
            }
        }

        if (!valid_request) absolute_relevance[i].clear();
    }

    return absolute_relevance;
}

std::vector<std::vector<RelativeIndex>>
SearchServer::calculationRelativeRelevances(std::vector<std::vector<int>> &absolute_relevance) {
    if (absolute_relevance.empty()) return {};

    size_t size_request = absolute_relevance.size();
    std::vector<std::vector<RelativeIndex>> relative_relevance(size_request);

    for (int i = 0; i < size_request; ++i) {
        if (absolute_relevance[i].empty()) continue;

        size_t size_absolute = absolute_relevance[i].size();
        auto max_abs_relevance = std::max_element(absolute_relevance[i].begin(), absolute_relevance[i].end());

        std::multimap<float, int> multimap_relative_relevance;

        for (int j = 0; j < size_absolute; j++) {
            if (absolute_relevance[i][j] == 0) continue;
            auto doc_id = j;
            auto rank = (float) absolute_relevance[i][j] / (float) (*max_abs_relevance);

            multimap_relative_relevance.emplace(rank, doc_id);
        }

        for (auto doc: multimap_relative_relevance) {
            auto d = multimap_relative_relevance.equal_range(doc.first);
            relative_relevance[i].emplace_back(RelativeIndex(doc.second, doc.first));
        }
        std::reverse(relative_relevance[i].begin(), relative_relevance[i].end());
    }

    return relative_relevance;
}
