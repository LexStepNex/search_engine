//#define DEBUG

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

#ifndef DEBUG
    programStarting();

    std::vector<std::string> testVec;

    testVec = ConverterJSON::getTextDocuments();

    for (const auto& i: testVec) {
        if(!i.empty())
        std::cout << i << "\n\n";
    }

    std::cout << "=======\n";
    std::cout << "max_responses: " << ConverterJSON::GetResponsesLimit() << "\n";
    std::cout << "=======\n";

#endif

    std::cout << "=======\n";
    auto vec_req = ConverterJSON::GetRequests();
    std::cout << "REQUESTS:\n";

    for (auto i: vec_req) {
        std::cout << i << "\n";
    }
    std::cout << "=======\n";

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