#ifndef SEARCH_ENGINE_FUNCTIONS_FOR_SEARCH_SERVER_H
#define SEARCH_ENGINE_FUNCTIONS_FOR_SEARCH_SERVER_H

#include <map>
#include <string>

#include "search_server.h"

std::map<std::string,int> getUniqueWords(const std::string& request);

std::vector<std::multimap<int, std::string>> swapCountWithWord(const std::vector<std::map<std::string, int>>&);
#endif //SEARCH_ENGINE_FUNCTIONS_FOR_SEARCH_SERVER_H
