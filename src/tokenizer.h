// Author: zhangfang
// Email: thuzhf@gmail.com

#ifndef TOKENIZER__H
#define TOKENIZER__H

#include <vector>
#include <string>

using namespace std;

class Tokenizer {
private:
    string delimiters;

public:
    Tokenizer();
    void set_delimiters(string);
    void Split(string, vector<string> &);
};

#endif