#ifndef SEARCH_ENGINE_FUNCTIONS_H
#define SEARCH_ENGINE_FUNCTIONS_H

#pragma once

#include "iostream"
#include <string>
#include <fstream>

#include "nlohmann/json.hpp"

void programStarting() {
    std::string pathConfig = "../config.json";
    std::ifstream configFile(pathConfig);

    nlohmann::json config;
    configFile >> config;
    configFile.close();

    std::string programName;
    if (config.find("config").value().find("name") != config.find("config").value().end()) {
        programName = config.find("config").value().find("name").value();
        if (programName.empty()) programName = "Unnamed";
    }
    else
        programName = "Unnamed";

    std::cout << "Welcome to the program \"" << programName << "\"" << std::endl;
};

#endif //SEARCH_ENGINE_FUNCTIONS_H
