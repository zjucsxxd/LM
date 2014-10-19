// Author: zhangfang
// Email: thuzhf@gmail.com

#include "locations_of_word.h"

using namespace std;

OneLocationOfWord::OneLocationOfWord() {
    word_nums = 0;
}

LocationsOfWord::LocationsOfWord() {
    sum = 0;
}

void LocationsOfWord::Update(size_t n) {
    sum += 1;
    bool found = false;
    for (list<OneLocationOfWord>::iterator it = locations.begin(); it != locations.end(); ++it) {
        if ((*it).doc_index == n) {
            (*it).word_nums += 1;
            found = true;
            break;
        }
    }
    if (!found) {
        OneLocationOfWord one_location;
        one_location.doc_index = n;
        one_location.word_nums = 1;
        locations.push_back(one_location);
    }
}

size_t LocationsOfWord::get_sum() {
    return sum;
}
