// Author: zhangfang
// Email: thuzhf@gmail.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <list>
#include <array>
#include <vector>

#include <cstdio>
#include <cstdlib>
#include <cmath>

#include "documents.h"
#include "locations_of_word.h"
#include "inverted_index.h"

using namespace std;

//1.打开文件，为防止文件太大，不一次性将文件全部读入内存（文件内容由多个文本文档顺序排列组成，各个文档之间以空行分隔）。
//2.在遇到文件结束符前，逐行读取文件内容，遇到空行则认为是一个文档的结束，将所读内容当成一个文档处理。
//  1.对于每个文档，记录其相关信息，同时构建inverted index，然后将记录的信息作为一个整体存入文档vector。
//    1.记录的信息包括但不限于：文档的总词数。
//3.读完文件，同时完成建立inverted index和文档vector。
//4.循环处理用户的query，首先记录用户的query，并拆分为单词vector。
//5.使用tf-idf weighting方法，smoothing方法为Jelinek-Mercer method，参数lambda=0.1，使用经过化简的公式。
//  1.将各个相关文档及其对应的与query的相关性的得分存入hash表中。
//6.对得到的hash表排序，然后输出前k(=10)个结果。

int main(int argc, char const *argv[])
{
    // 1.
    const string input_file_name = "../data/sample.txt";
    ifstream input_file(input_file_name);

    // 2.
    Documents docs;
    InvertedIndex inverted_index;

    string first_line; // 第一行是总的文档数
    int docs_num;
    getline(input_file, first_line);
    docs_num = atoi(first_line.data());

    while (!input_file.eof()) {
        vector<string> tmp;
        string line;
        while (getline(input_file, line) && !line.empty()) {
            tmp.push_back(line);
        }
        if (tmp.empty())  continue;
        
        Document doc;
        doc.Parse(tmp);
        docs.AddDocument(doc);
        inverted_index.Update(tmp, docs.get_docs_num() - 1);
    }

    return 0;
}
