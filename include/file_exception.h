#ifndef SEARCH_ENGINE_FILE_EXCEPTION_H
#define SEARCH_ENGINE_FILE_EXCEPTION_H


#include <exception>
#include <string>

/*Переопределяем класс для вывода исключений без дополнительной информации
 * по типу ": iostream error"
 */
class ConfigFileException : public std::exception {
public:
    explicit ConfigFileException(const std::string& _message) : message(_message) {}

    virtual const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

#endif //SEARCH_ENGINE_FILE_EXCEPTION_H
