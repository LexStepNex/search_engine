#ifndef SEARCH_ENGINE_SEARCH_SERVER_H
#define SEARCH_ENGINE_SEARCH_SERVER_H

#include <vector>

#include "inverted_index.h"

struct RelativeIndex {
    size_t doc_id;
    float rank;

    bool operator==(const RelativeIndex &other) const {
        return (doc_id == other.doc_id && rank == other.rank);
    }

    RelativeIndex& operator=(const RelativeIndex &index) {
        if (this != &index) {
            doc_id = index.doc_id;
            rank = index.rank;
        }
        return *this;
    }

    std::pair<int, float> inPair() {
        return std::make_pair(doc_id,rank);
    }

};

class SearchServer {
public:
    SearchServer(InvertedIndex &idx);

    //Метод обработки поисковых запросов
    std::vector<std::vector<RelativeIndex>> search(const std::vector<std::string>& queries_input);

private:
    InvertedIndex _index;

    void addWordCount(std::vector<std::map<std::string, int>> &words_in_queries);
    std::vector<std::vector<int>> calculationAbsoluteRelevances(const std::vector<std::multimap<int, std::string>>& sort_requests);
    std::vector<std::vector<RelativeIndex>> calculationRelativeRelevances(std::vector<std::vector<int>>&);
};

#endif //SEARCH_ENGINE_SEARCH_SERVER_H