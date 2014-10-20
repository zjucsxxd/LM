// Author: zhangfang
// Email: thuzhf@gmail.com

#ifndef DOCUMENTS__H
#define DOCUMENTS__H

#include <string>
#include <vector>

using namespace std;

class Document {
public:
    string document_name;
    string authors;
    string time;
    string conference;
    string abstract;
    size_t words_sum;

    Document();
    void Parse(vector<string>);
};

class Documents {
private:
    size_t all_words_sum;

public:
    Documents();
    vector<Document> docs;
    void AddDocument(Document);
    size_t get_docs_num();
    size_t get_all_words_sum();
};

#endif
