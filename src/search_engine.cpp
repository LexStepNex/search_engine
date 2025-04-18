//#define DEBUG

#include <iostream>

#include "initial_tests.h"
#include "general_functions.h"
#include "converter_json.h"
#include "inverted_index.h"
#include "search_server.h"

int main() {
#ifndef DEBUG

    try {
        initialTests();
    }
    catch (const ConfigFileException &x) {
        std::cerr << x.what() << '\n';
        return 0;
    }

    programStarting();

    try{
        checkFile("config");
        checkFile("requests");
    } catch (const std::logic_error& x) {
        std::cerr << x.what();
    }
#endif
    std::string answerUser;
    while(answerUser != "start") {
        std::cout << "Enter \"start\" to begin the search: ";

        std::cin >> answerUser;
        toLowerCase(answerUser);

        if (answerUser != "start") {
            std::cout << "Error. ";
        }
    }

    InvertedIndex indexDoc;

    indexDoc.UpdateDocumentBase(ConverterJSON::getTextDocuments());

    SearchServer searchServer(indexDoc);
    auto resultRequests = searchServer.search(ConverterJSON::GetRequests());

    ConverterJSON::putAnswers(convertRelativeIndex(resultRequests));


    std::cout << "Click Enter for exit program\n";
    std::cin.ignore();
    std::cin.get();

    return 0;
}