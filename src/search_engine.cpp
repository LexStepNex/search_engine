#include <iostream>
#include <exception>

#include "initial_tests.h"
#include "functions.h"

int main() {
    try {
        initialTests();
    }
    catch (const ConfigFileException& x) {
        std::cerr << x.what() << '\n';
        return 0;
    }

    programStarting();

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