#include "general_functions.h"

#include <iostream>
#include <fstream>
#include <regex>
#include <algorithm>
#include <thread>

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

std::string getSerialNumber(const unsigned& number) {
    std::string numberStr = std::to_string(number);

    size_t maxAddZero = 2;
    size_t quantityZero = maxAddZero - numberStr.size();

    std::string serialNumber;
    for (int i =0; i <= quantityZero;i++) {
        serialNumber += '0';
    }

    serialNumber += numberStr;

    return serialNumber;
}

void toLowerCase(std::string& str) {
    std::transform(str.begin(),str.end(),str.begin(), tolower);
}

void checkFile(const std::string& fileName) {
    std::string openingQuestion;
    std::string negativeAnswer;

    if(fileName == "config") {
        openingQuestion = "Check if all file paths are added to the \"config.json\" file in the \"files\" item?\n";
        negativeAnswer = "Add the desired file paths to the \"config.json\" file.\n";

    } else if (fileName == "requests"){
        openingQuestion = "Check if all requests are added to the \"requests.json\" file in the \"requests\" item?\n";
        negativeAnswer = "Add the requests of interest to the \"requests.json\" file.\n";
    } else {
        throw std::logic_error("unknown value for the program is set in the \"checkFile\" function\n");
    }

    std::string answerUser;
    bool positiveAnswer = false;

    while (!positiveAnswer) {
        std::cout << openingQuestion;
        std::cout << R"(Input "yes" / "no": )";

        std::cin >> answerUser;
        toLowerCase(answerUser);

        positiveAnswer = answerUser == "yes" || answerUser == "y";

        if(answerUser == "no" || answerUser == "n") {
            std::cout << negativeAnswer;
            std::this_thread::sleep_for(std::chrono::milliseconds (100));
            continue;
        }

        if(!positiveAnswer) {
            std::cout << "Please input \"yes\" or \"no\"\n";
        }
    }
}