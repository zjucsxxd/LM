// Author: zhangfang
// Email: thuzhf@gmail.com

#include "inverted_index.h"

using namespace std;

void InvertedIndex::Update(vector<string> doc, size_t n) {
    Document d;
    d.parse(doc);
    for (auto it = doc.begin(); it != doc.end(); ++it) {
        if ((*it).compare(0, 2, "#*") == 0 || // title
            (*it).compare(0, 2, "#@") == 0 || // authors
            (*it).compare(0, 2, "#t") == 0 || // time
            (*it).compare(0, 2, "#c") == 0 || // conference
            (*it).compare(0, 2, "#!") == 0) { // abstract
            string substring = (*it).substr(2);
            vector<string> tokens;
            tokenizer.Split(substring, tokens);
            d.words_sum += tokens.size();
            for (auto it2 = tokens.begin(); it2 != tokens.end(); ++it2) {
                inverted_index[*it2].Update(n);
            }
        }
    }
    docs.AddDocument(d);
}

LocationsOfWord * InvertedIndex::get_word_locations(string w) {
    return &inverted_index[w];
}

vector<Document> * InvertedIndex::get_docs() {
    return &(docs.docs);
}

size_t InvertedIndex::GetAllWordsSum() {
    return docs.get_all_words_sum();
}

size_t InvertedIndex::GetDocsNum() {
    return docs.get_docs_num();
}