#ifndef SEARCH_ENGINE_INITIAL_TESTS_H
#define SEARCH_ENGINE_INITIAL_TESTS_H

#include <fstream>

#include "nlohmann/json.hpp"

#include "file_exception.h"

bool findFieldConfig(std::ifstream &file);

void isOpenFileConfigJSON() {
    std::ifstream configJSON("../config.json");

    if (!configJSON.is_open()) {
        throw ConfigFileException("config file is missing");
    }
    if (!findFieldConfig(configJSON)) {
        throw ConfigFileException("config file is empty");
    }

    configJSON.close();
}

bool findFieldConfig(std::ifstream &file) {
    nlohmann::json config;
    file >> config;

    if (config.find("config") != config.end())
        return true;
    else
        return false;
}

void testRequestsJSON() {
    std::string path = "../requests.json";

    std::ifstream requestsFile(path);

    if (!requestsFile.is_open()) {
        std::ofstream createRequestsJSON(path);
        nlohmann::json requests;

        requests["requests"].emplace_back("write your request");
        requests["requests"].emplace_back("write your request");

        createRequestsJSON << requests;

        createRequestsJSON.close();
        return;
    }

    requestsFile.close();
}

void testAnswersJSON() {
    std::string path = "../answers.json";

    std::ofstream createAnswersJSON(path); //открытие или создания файла answers.json

    if(!createAnswersJSON.is_open()) {
        std::cerr << "Failed to open/create the file answer.json\n";
        return;
    }

    nlohmann::json answers;
    answers["answers"] = {};
    createAnswersJSON << answers; //обнуление или первичная запись

    createAnswersJSON.close();
}

void initialTests() {
    isOpenFileConfigJSON();
    testRequestsJSON();
    testAnswersJSON();
}

#endif //SEARCH_ENGINE_INITIAL_TESTS_H
