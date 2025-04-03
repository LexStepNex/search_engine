#include "converter_json.h"

#include <fstream>
#include <string>

#include "nlohmann/json.hpp"

#include "functions_for_work_with_files.h"
#include "general_functions.h"
#include "functions_for_converter_json.h"

std::vector<std::string> ConverterJSON::getTextDocuments() {
    nlohmann::json config = getJsonData("../config.json");

    if (!(config.find("files") != config.end()))
        return {};

    std::vector<std::string> textInFiles;

    for (std::string path: config.find("files").value()) {
        try {
            textInFiles.push_back(readingTextFromFiles(path));
        } catch (const ConfigFileException &x) {
            textInFiles.emplace_back("");//для правильной индексации, исходя из
            std::cerr << x.what();
        }
    }

    return textInFiles;
}

int ConverterJSON::GetResponsesLimit() {
    const int DEFAULT_LIMIT = 5;

    nlohmann::json config = getJsonData("../config.json");

    if (config.find("config").value().find("max_responses") != config.find("config").value().end()) {
        try {
            int limitResponses = config.find("config").value().find("max_responses").value();
            return limitResponses;
        } catch (...) {
            std::cout << "\nUse default limit responses\n";
            return DEFAULT_LIMIT;
        }
    } else {
        return DEFAULT_LIMIT;
    }
}

std::vector<std::string> ConverterJSON::GetRequests() {
    nlohmann::json requests = getJsonData("../requests.json");

    if (!(requests.find("requests") != requests.end())) {
        std::cout << "Field \"requests\" not found\n";
        return {};
    }

    const int MAX_COUNT_REQUESTS = 1000;

    if (requests.find("requests").value().size() > MAX_COUNT_REQUESTS) {
        std::cout << "Maximum number of requests exceeded =" << MAX_COUNT_REQUESTS << "\n";
    }

    std::vector<std::string> vec_requests;
    for (const auto &request: requests.find("requests").value()) {
        try {
            int wordsCount = wordCountInString(request);

            if (wordsCount < 1 || wordsCount > 10) {
                std::cerr << "Request: " << request << " incorrect\n";
                std::cerr << "The query should have between 1 and 10 words\n";
                vec_requests.emplace_back("");//некорректный запрос
            } else {
                vec_requests.emplace_back(request);
            }
        } catch (const ConfigFileException &x) {
            std::cerr << x.what();
        }
    }

    return vec_requests;
}


void ConverterJSON::putAnswers(const std::vector<std::vector<std::pair<int, float>>> &answers) {
    nlohmann::json answersJSON;

    nlohmann::json allRequestsJSON;//для более удобного размещения данных

    size_t requestNumber = 1;
    //разбор по каждому запросу
    for (const auto& request: answers) {
        std::string requestNumberStr = "request" + getSerialNumber(requestNumber);

        if (request.empty()) {
            allRequestsJSON[requestNumberStr]["result"] = false;
            requestNumber++;
            continue;
        }

        allRequestsJSON[requestNumberStr]["result"] = true;
        //разбор по каждому документу
        std::vector<nlohmann::json> allRelevance = pairsToRelevance(request);

        allRequestsJSON[requestNumberStr]["relevance"] = allRelevance;

        ++requestNumber;
    }

    answersJSON["answers"] = allRequestsJSON;

    std::ofstream fileAnswer("../answers.json");
    fileAnswer << answersJSON;
    fileAnswer.close();
}
