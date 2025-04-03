#ifndef SEARCH_ENGINE_CONVERTER_JSON_H
#define SEARCH_ENGINE_CONVERTER_JSON_H

#pragma once

#include <vector>
#include <string>

#include "nlohmann/json.hpp"

class ConverterJSON {
public:
    ConverterJSON() = default;

    //Метод получения содержимого файлов из config.json
    static std::vector<std::string> getTextDocuments();

    //Метод получения максимального числа ответов на один запрос
    static int GetResponsesLimit();

    //Метод получения запросов из файла requests.json
    static std::vector<std::string> GetRequests();

    //Метод отправки ответов в файл answers.json
    static void putAnswers(const std::vector<std::vector<std::pair<int, float>>>& answers);
};

#endif //SEARCH_ENGINE_CONVERTER_JSON_H
