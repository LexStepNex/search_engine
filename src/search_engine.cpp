#define DEBUG

#include <iostream>
#include "initial_tests.h"
#include "general_functions.h"
#include "ConverterJSON.h"

int main() {
    try {
        initialTests();
    }
    catch (const ConfigFileException &x) {
        std::cerr << x.what() << '\n';
        return 0;
    }

    programStarting();
#ifndef DEBUG

    std::vector<std::string> testVec;

    testVec = ConverterJSON::getTextDocuments();

    for (const auto& i: testVec) {
        if(!i.empty())
        std::cout << i << "\n\n";
    }

    std::cout << "=======\n";
    std::cout << "max_responses: " << ConverterJSON::GetResponsesLimit() << "\n";
    std::cout << "=======\n";


    std::cout << "=======\n";
    auto vec_req = ConverterJSON::GetRequests();
    std::cout << "REQUESTS:\n";

    for (auto i: vec_req) {
        std::cout << i << "\n";
    }
    std::cout << "=======\n";


    std::vector<std::vector<std::pair<int, float>>> vecVecsPairs;
    std::vector<std::pair<int, float>> vecPairs1;
    std::vector<std::pair<int, float>> vecPairs2 = {{0,0.23f}, {1,0.33f},{3,0.73f}};
    std::vector<std::pair<int, float>> vecPairs3 = {{0,0.98f},{4,0.88f}};
    std::vector<std::pair<int, float>> vecPairs4 = {{0,0.23f}};

    vecVecsPairs.push_back(vecPairs1);
    vecVecsPairs.push_back(vecPairs2);
    vecVecsPairs.push_back(vecPairs3);
    vecVecsPairs.push_back(vecPairs4);

    ConverterJSON::putAnswers(vecVecsPairs);
#endif

    /*
    std::ifstream file("../config.json");

    nlohmann::json test;
    file >> test;

    std::cout << test.find("config").value().find("name").value() << "\n";

    std::vector<std::string> vec;
    for (auto i : test.find("files").value()) {
        vec.push_back(i);
    }

    std::cout << "source files:\n";
    for(auto i: vec) {
        std::cout << i << "\n";
    }
        file.close();
*/

    return 0;
}
