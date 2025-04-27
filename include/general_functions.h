#ifndef SEARCH_ENGINE_GENERAL_FUNCTIONS_H
#define SEARCH_ENGINE_GENERAL_FUNCTIONS_H

#include <string>

void programStarting();

bool correctWord(const std::string &word);

int wordCountInString(const std::string& str);

std::string getSerialNumber(const unsigned& number);

void toLowerCase(std::string& str);

void checkFile(const std::string& fileName);
#endif //SEARCH_ENGINE_GENERAL_FUNCTIONS_H
