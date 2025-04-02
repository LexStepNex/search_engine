#include "functions_for_ConverterJSON.h"


std::vector<nlohmann::json>pairsToRelevance(const std::vector<std::pair<int,float>>& docsRank) {
    std::vector<nlohmann::json> allRelevance;

    //разбор по каждому документу
    for (auto docIdRank: docsRank) {
        nlohmann::json relevance;
        relevance["docid"] = docIdRank.first;
        relevance["rank"] = docIdRank.second;

        allRelevance.emplace_back(relevance);
    }

    return allRelevance;
}