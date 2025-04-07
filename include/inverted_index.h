#ifndef SEARCH_ENGINE_INVERTED_INDEX_H
#define SEARCH_ENGINE_INVERTED_INDEX_H

#include <string>
#include <vector>
#include <map>
#include <mutex>

struct Entry {
    size_t doc_id, count;

    //Перегрузка оператора необходима для проведения тестовых сценариев
    bool operator ==(const Entry& other) const {
        return (doc_id == other.doc_id &&
                count == other.count);
    }
};

class InvertedIndex {
public:
    InvertedIndex() = default;

    //метод обновляет/заполняет базу документов
    void UpdateDocumentBase(const std::vector<std::string>& input_docs);

    //метод определяет количество вхождений слова в загруженной базе документов
    std::vector<Entry> GetWordCount(const std::string& word);

private:
    std::vector<std::string> docs; // список содержимого документов
    std::map<std::string, std::vector<Entry>> freq_dictionary; // частотный словарь

    std::mutex indexing_mutex;
    void docIndexing (const std::string& doc, size_t id);
};

#endif //SEARCH_ENGINE_INVERTED_INDEX_H
