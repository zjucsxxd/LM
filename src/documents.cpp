// Author: zhangfang
// Email: thuzhf@gmail.com

#include "documents.h"

using namespace std;

Document::Document() {
    words_sum = 0;
}

void Document::Parse(vector<string> doc) {
    for (auto it = doc.begin(); it != doc.end(); ++it) {
        if ((*it).compare(0, 2, "#*") == 0) { // document title
            document_name = (*it).substr(2);
        } else if ((*it).compare(0, 2, "#@") == 0) { // authors
            authors = (*it).substr(2);
        } else if ((*it).compare(0, 2, "#t") == 0) { // time
            time = (*it).substr(2);
        } else if ((*it).compare(0, 2, "#c") == 0) { // conference
            conference = (*it).substr(2);
        } else if ((*it).compare(0, 2, "#!") == 0) { // abstract
            //abstract = (*it).substr(2);
        }
    }
}

Documents::Documents() {
    all_words_sum = 0;
}

void Documents::AddDocument(Document d) {
    docs.push_back(d);
    all_words_sum += d.words_sum;
}

size_t Documents::get_docs_num() {
    return docs.size();
}

size_t Documents::get_all_words_sum() {
    return all_words_sum;
}