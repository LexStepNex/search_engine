#include "inverted_index.h"

#include <sstream>

void InvertedIndex::UpdateDocumentBase(const std::vector<std::string>& input_docs) {
    docs.resize(input_docs.size());
    docs = input_docs;

    std::map<std::string, std::vector<Entry>> test;

    int docsSize = docs.size();

    for (size_t id = 0; id < docsSize; id++) {
        std::stringstream stringStream(docs[id]);
        std::string word;

        while(stringStream >> word) {
            if(freq_dictionary.find(word) != freq_dictionary.end()) {
                if (id < freq_dictionary[word].size()) {
                    freq_dictionary[word][id].count++;
                } else {
                    freq_dictionary[word].push_back({id,1});
                }
            } else {
                freq_dictionary[word];
                freq_dictionary[word].push_back({id,1});
            }
        }
    }
}

std::vector<Entry> InvertedIndex::GetWordCount(const std::string &word) {
    if (freq_dictionary.find(word) != freq_dictionary.end()) {
        return freq_dictionary.find(word)->second;
    } else {
        return std::vector<Entry>();
    }
}

