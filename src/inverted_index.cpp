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

    size_t docsSize = docs.size();

    std::vector<std::thread> indexing;

    for (size_t id = 0; id < docsSize; id++) {
        indexing.emplace_back(&InvertedIndex::docIndexing, this, docs[id], id);
    }

    for (size_t i = 0; i < docsSize; i++) {
        indexing[i].join();
    }
}

void InvertedIndex::docIndexing(const std::string &doc, size_t id) {
    std::stringstream stringStream(doc);
    std::string word;

    while (stringStream >> word) {
        std::lock_guard<std::mutex> lock_indexing(indexing_mutex);

        if (freq_dictionary.find(word) != freq_dictionary.end()) {

            if (id < freq_dictionary[word].size()) {
                freq_dictionary[word][id].count++;
            } else {
                freq_dictionary[word].push_back({id, 1});
            }
        } else {

            freq_dictionary[word];
            freq_dictionary[word].push_back({id, 1});
        }
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
    return docs.size();
}
