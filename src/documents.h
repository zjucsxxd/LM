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
    int words_sum;

    void Parse(vector<string>);
};

class Documents {
private:
    vector<Document> docs;

public:
    void AddDocument(Document);
    size_t get_docs_num();
};

#endif
