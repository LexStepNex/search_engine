#ifndef SEARCH_ENGINE_FUNCTIONS_FOR_CONVERTER_JSON_H
#define SEARCH_ENGINE_FUNCTIONS_FOR_CONVERTER_JSON_H


#include <vector>

#include "nlohmann/json.hpp"

std::vector<nlohmann::json>pairsToRelevance(const std::vector<std::pair<int,float>>&);

#endif //SEARCH_ENGINE_FUNCTIONS_FOR_CONVERTER_JSON_H
