#ifndef SEARCH_ENGINE_FUNCTIONS_FOR_WORK_WITH_FILES_H
#define SEARCH_ENGINE_FUNCTIONS_FOR_WORK_WITH_FILES_H

#include <string>

#include "nlohmann/json.hpp"

std::string readingTextFromFiles(const std::string &path);
nlohmann::json getJsonData(const std::string &path);

#endif //SEARCH_ENGINE_FUNCTIONS_FOR_WORK_WITH_FILES_H