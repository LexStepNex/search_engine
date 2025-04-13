//#define DEBUG

#include <iostream>

#include "initial_tests.h"
#include "general_functions.h"
#include "converter_json.h"
#include "inverted_index.h"
#include "search_server.h"

std::vector<std::vector<std::pair<int, float>>>
convertRelativeIndex(std::vector<std::vector<RelativeIndex>> &relativeIndexes) {
    if (relativeIndexes.empty()) return {};

    size_t size_relativeIndexes = relativeIndexes.size();
    std::vector<std::vector<std::pair<int, float>>> vec(size_relativeIndexes);

    for (int i = 0; i < size_relativeIndexes; i++) {
        size_t size_valid_doc = relativeIndexes[i].size();
        vec[i].resize(size_valid_doc);

        for (int j = 0; j < size_valid_doc; ++j) {
            vec[i][j] = relativeIndexes[i][j].inPair();
        }
    }

    return vec;
}

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
    InvertedIndex indexDoc;

    const std::vector<std::string> docs = {
            "london is the capital of great britain",
            "paris is the capital of france",
            "berlin is the capital of germany",
            "rome is the capital of italy",
            "madrid is the capital of spain",
            "lisboa is the capital of portugal",
            "bern is the capital of switzerland",
            "moscow is the capital of russia",
            "kiev is the capital of ukraine",
            "minsk is the capital of belarus",
            "astana is the capital of kazakhstan",
            "beijing is the capital of china",
            "tokyo is the capital of japan",
            "bangkok is the capital of thailand",
            "welcome to moscow the capital of russia the third rome",
            "amsterdam is the capital of netherlands",
            "helsinki is the capital of finland",
            "oslo is the capital of norway",
            "stockholm is the capital of sweden",
            "riga is the capital of latvia",
            "tallinn is the capital of estonia",
            "warsaw is the capital of poland",
    };

    indexDoc.UpdateDocumentBase(docs);

    SearchServer searchServer(indexDoc);
    const std::vector<std::string> request = {"moscow is the capital of russia"};
    auto vec = searchServer.search(request);
    ConverterJSON::putAnswers(convertRelativeIndex(vec));
    /*
    auto vec = indexDoc.freq_dictionary;

    std::ofstream file("../answers.json");
    for (auto i : vec) {
        file << "word: " << i.first << "\n";
        for (auto j: i.second) {
            file << "   id: " << j.doc_id << " count: " << j.count << "\n";
        }
        file << "\n";
    }
    file.close();
*/

    //auto vec = searchServer.search(request);
    //auto vec2 = convertRelativeIndex(vec);
    //ConverterJSON::putAnswers(vec2);
#endif

    return 0;
}
