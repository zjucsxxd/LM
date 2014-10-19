#include "inverted_index.h"

using namespace std;

void InvertedIndex::Update(vector<string> doc, size_t n) {
    for (vector<string>::iterator it = doc.begin(); it != doc.end(); ++it) {
        if ((*it).compare(0, 2, "#*") == 0 || // title
            (*it).compare(0, 2, "#@") == 0 || // authors
            (*it).compare(0, 2, "#t") == 0 || // time
            (*it).compare(0, 2, "#c") == 0 || // conference
            (*it).compare(0, 2, "#!") == 0) { // abstract
            string substring = (*it).substr(2);
            vector<string> tokens;
            tokenizer.Split(substring, tokens);
            for (vector<string>::iterator it2 = tokens.begin(); it2 != tokens.end(); ++it2) {
                inverted_index[*it2].Update(n);
            }
        }
    }
}
