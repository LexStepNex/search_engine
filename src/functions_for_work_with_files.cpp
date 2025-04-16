#include "functions_for_work_with_files.h"

#include <fstream>
#include <iostream>

#include "file_exception.h"
#include "general_functions.h"

std::string readingTextFromFiles(const std::string &path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::string error = "The file is in the path \"" + path + "\" was not found\n";
        throw ConfigFileException(error);
    }

    std::string textInFile;
    std::string word;
    const int MAX_WORD_COUNT = 1000;
    int countWord = 0;

    const int MAX_COUNT_CHAR = 100;

    while (file >> word) {

        if (word.size() >= MAX_COUNT_CHAR) {
            std::string error = "A word longer than 100 characters was found in the \"" + path + "\" file\n";
            throw ConfigFileException(error);
        } else if (!correctWord(word)) {
            std::string error = "The word \"" + word + "\" was found in the file \"" +
                                path + "\", containing not only Latin letters\n";
            throw ConfigFileException(error);
        }

        countWord++;

        if (countWord > MAX_WORD_COUNT) {
            std::string error = "The \"" + path + "\" file contains over 1000 words.\n";
            throw ConfigFileException(error);
        }

        if (countWord == 0) {
            textInFile += word;
        } else {
            textInFile += " " + word;
        }

    }

    return textInFile;
}

nlohmann::json getJsonData(const std::string &path) {
    if (path.substr(path.size() - 5, path.size() - 1) != ".json") return {};

    nlohmann::json dataJSON;

    std::ifstream jsonFile(path);
    if (!jsonFile.is_open()) {
        std::cerr << "Error: Unable to open file " << path << std::endl;
        return {};
    }

    try {
        jsonFile >> dataJSON;
    } catch (const nlohmann::json::parse_error& x) {
        std::cerr << "Read error JSON: " << x.what() << std::endl;
    } catch (const std::exception& x) {
        std::cerr << "Error: " << x.what() << std::endl;
    }

    jsonFile.close();

    return dataJSON;
}