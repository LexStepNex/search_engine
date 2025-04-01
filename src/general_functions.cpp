#include "general_functions.h"

#include <iostream>
#include <fstream>
#include <regex>

#include "nlohmann/json.hpp"

#include "file_exception.h"

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
}

bool correctWord(const std::string &word) {
    std::regex patternWord("([a-zA-Z]+)");
    return std::regex_match(word.c_str(), patternWord);
}

int wordCountInString(const std::string& str) {
    std::stringstream strStream(str);

    std::string word;
    int count = 0;
    while (strStream >> word) {
        if (!correctWord(word)) {
            std::string error = "Words containing only Latin letters should be used\n";
            throw ConfigFileException(error);
        }
        count++;
    }

    return count;
}