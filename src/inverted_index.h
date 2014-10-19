// Author: zhangfang
// Email: thuzhf@gmail.com

#ifndef INVERTED_INDEX__H
#define INVERTED_INDEX__H

#include <vector>
#include <string>
#include <unordered_map>

#include "locations_of_word.h"
#include "tokenizer.h"

using namespace std;

class InvertedIndex {
private:
    unordered_map<string, LocationsOfWord> inverted_index;
    Tokenizer tokenizer;

public:
    void Update(vector<string>, size_t);
};

#endif
