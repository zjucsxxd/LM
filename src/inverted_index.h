// Author: zhangfang
// Email: thuzhf@gmail.com

#ifndef INVERTED_INDEX__H
#define INVERTED_INDEX__H

#include <vector>
#include <string>
#include <unordered_map>

#include "locations_of_word.h"
#include "tokenizer.h"
#include "documents.h"

using namespace std;

class InvertedIndex {
private:
    unordered_map<string, LocationsOfWord> inverted_index;
    Documents docs;
    Tokenizer tokenizer;

public:
    void Update(vector<string>, size_t);
    LocationsOfWord * get_word_locations(string);
    vector<Document> * get_docs();
    size_t GetAllWordsSum();
    size_t GetDocsNum();
};

#endif
