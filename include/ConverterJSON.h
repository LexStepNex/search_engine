//
// Created by User on 26.03.2025.
//

#ifndef SEARCH_ENGINE_CONVERTERJSON_H
#define SEARCH_ENGINE_CONVERTERJSON_H

#pragma once

#include <vector>
#include <string>

#include "nlohmann/json.hpp"

class ConverterJSON {
public:
    ConverterJSON() = default;

    //Метод получения содержимого файлов из config.json
    std::vector<std::string> getTextDocuments();

    //Метод получения максимального числа ответов на один запрос
    int GetResponsesLimit();

    //Метод получения запросов из файл requests.json
    std::vector<std::string> GetRequests();

    //Метод отправки ответов в файл answers.json
    void putAnswers(std::vector<std::vector<std::pair<int,float>>> answers);
};


#endif //SEARCH_ENGINE_CONVERTERJSON_H
