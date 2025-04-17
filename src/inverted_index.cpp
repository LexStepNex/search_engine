#include "inverted_index.h"

#include <sstream>
#include <thread>
#include <vector>

#include <iostream>

InvertedIndex::InvertedIndex(const InvertedIndex &other_index) {
    docs = other_index.docs;
    freq_dictionary = other_index.freq_dictionary;
}

void InvertedIndex::UpdateDocumentBase(const std::vector<std::string> &input_docs) {
    docs.resize(input_docs.size());
    docs = input_docs;

    freq_dictionary.clear();

    size_t docsSize = docs.size();


    std::vector<std::thread> indexing;

    for (size_t id = 0; id < docsSize; id++) {
        indexing.emplace_back(&InvertedIndex::docIndexing, this, std::cref(docs[id]), id);
    }

    for (size_t i = 0; i < docsSize; i++) {
        indexing[i].join();
    }

    //удаляем лишние включения доукментов, в которых слова не найдены
    for(auto& i : freq_dictionary) {
        for (int j = 0; j < i.second.size(); ) {
            if(i.second[j].count == 0) {
                i.second.erase(i.second.begin() + j);
                continue;
            }

            ++j;
        }
    }
}

void InvertedIndex::docIndexing(const std::string &doc, size_t id) {
    std::stringstream stringStream(doc);
    std::string word;

    while (stringStream >> word) {
        std::lock_guard<std::mutex> lock_indexing(indexing_mutex);

        // Инициализация вектора, если слово не найдено
        auto& entries = freq_dictionary[word];
        if (entries.empty() || id >= entries.size()) {
            entries.resize(std::max(entries.size(), id + 1), Entry{0, 0});
        }

        entries[id].doc_id = id;
        entries[id].count++;
    }
}

std::vector<Entry> InvertedIndex::GetWordCount(const std::string &word) {
    if (freq_dictionary.find(word) != freq_dictionary.end()) {
        return freq_dictionary.find(word)->second;
    } else {
        return {};
    }
}

int InvertedIndex::getSizeDocs() {
    return (int) docs.size();
}
