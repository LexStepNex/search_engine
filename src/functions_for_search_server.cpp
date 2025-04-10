#include "functions_for_search_server.h"

#include <sstream>

std::map<std::string, int> getUniqueWords(const std::string &request) {
    std::map<std::string, int> unique_words;

    std::stringstream stringStream(request);
    std::string word;

    while (stringStream >> word) {
        if (!(unique_words.find(word) != unique_words.end())) {
            unique_words[word] = 0;
        }
    }

    return unique_words;
}

std::vector<std::multimap<int, std::string>> swapCountWithWord(const std::vector<std::map<std::string, int>>& words_in_queries) {
    std::vector<std::multimap<int, std::string>> sort_requests;

    for(auto &words_in_request: words_in_queries) {
        std::multimap<int, std::string> sort_request;
        for (auto &word_count: words_in_request) {
            sort_request.emplace(word_count.second, word_count.first);
        }
        sort_requests.emplace_back(sort_request);
    }

    return sort_requests;
}