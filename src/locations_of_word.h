// Author: zhangfang
// Email: thuzhf@gmail.com

#ifndef LOCATIONS_OF_WORD__H
#define LOCATIONS_OF_WORD__H

#include <iostream> 
#include <list>

using namespace std;

class OneLocationOfWord {
public:
    int doc_index;
    int word_nums;

    OneLocationOfWord();
};

class LocationsOfWord {
private:
    size_t sum; // sums of this words in all docs
    list<OneLocationOfWord> locations;

public:
    LocationsOfWord();
    void Update(size_t);
    size_t get_sum();
};

#endif
