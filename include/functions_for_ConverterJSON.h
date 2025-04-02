#ifndef SEARCH_ENGINE_FUNCTIONS_FOR_CONVERTERJSON_H
#define SEARCH_ENGINE_FUNCTIONS_FOR_CONVERTERJSON_H

#pragma once

#include <vector>

#include "nlohmann/json.hpp"

std::vector<nlohmann::json>pairsToRelevance(const std::vector<std::pair<int,float>>&);

#endif //SEARCH_ENGINE_FUNCTIONS_FOR_CONVERTERJSON_H
