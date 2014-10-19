#include "tokenizer.h"

using namespace std;

Tokenizer::Tokenizer() {
    delimiters = "\n\r\t !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
}

void Tokenizer::set_delimiters(string s) {
    delimiters = s;
}

void Tokenizer::Split(string src, vector<string> &dst) {
    size_t p1 = 0, p2 = 0;
    while (true) {
        p1 = src.find_first_not_of(delimiters, p2); // word begin
        if (p1 == string::npos)  break;
        p2 = src.find_first_of(delimiters, p1); // word end
        if (p2 == string::npos) {
            p2 = src.length();
        }
        dst.push_back(src.substr(p1, p2 - p1));
    }
}
