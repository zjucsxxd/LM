#include "documents.h"

using namespace std;

void Document::Parse(vector<string> doc) {
    for (vector<string>::iterator it = doc.begin(); it != doc.end(); ++it) {
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

void Documents::AddDocument(Document d) {
    docs.push_back(d);
}

size_t Documents::get_docs_num() {
    return docs.size();
}
