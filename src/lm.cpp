// Author: zhangfang
// Email: thuzhf@gmail.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <map>
#include <list>
#include <array>
#include <vector>
#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <cmath>

#include "documents.h"
#include "locations_of_word.h"
#include "inverted_index.h"
#include "tokenizer.h"
#include "estimator.h"

using namespace std;

//1.打开文件，为防止文件太大，不一次性将文件全部读入内存（文件内容由多个文本文档顺序排列组成，各个文档之间以空行分隔）。
//2.在遇到文件结束符前，逐行读取文件内容，遇到空行则认为是一个文档的结束，将所读内容当成一个文档处理。
//  1.对于每个文档，记录其相关信息，同时构建inverted index，然后将记录的信息作为一个整体存入文档vector。
//    1.记录的信息包括但不限于：文档的总词数。
//3.读完文件，同时完成建立inverted index和文档vector。
//4.循环处理用户的query，首先记录用户的query，并拆分为单词vector。
//5.使用tf-idf weighting方法，smoothing方法为Jelinek-Mercer method，参数lambda=0.1，使用经过化简的公式。
//  1.将各个相关文档及其对应的与query的相关性的得分存入hash表中。
//6.对得到的hash表排序，然后输出前k(<=10)个结果。

auto cmp = [](pair<size_t, double> const & a, pair<size_t, double> const & b)
{
     return a.second != b.second?  a.second > b.second : a.first < b.first;
};

int main(int argc, char const *argv[])
{
    // 1.
    string input_file_name = "../data/sample.txt";
    if (argc == 2) {
        input_file_name = argv[1];
    }
    ifstream input_file(input_file_name);
    if (!input_file.is_open()) {
        cout << "Error opening file" << endl;
        exit(EXIT_FAILURE);
    }

    // 2.
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

        inverted_index.Update(tmp, inverted_index.GetDocsNum()); // index from 0

        static size_t count = 0;
        if (count++ % 5000 == 0) {
            cout << "Index: " << count - 1 << endl;
        }
    }

    // 3.
    // 4.
    string q;
    cout << "Please input your query: ";
    while (getline(cin, q)) {
        Tokenizer tokenizer;
        vector<string> query;
        tokenizer.Split(q, query);

        // 5.
        Estimator estimator;
        estimator.set_lambda(0.1);
        map<size_t, double> scores;
        for (vector<string>::iterator it = query.begin(); it != query.end(); ++it) {
            LocationsOfWord *LOW = inverted_index.get_word_locations(*it);
            for (auto it2 = LOW->locations.begin(); it2 != LOW->locations.end(); ++it2) {
                size_t index = it2->doc_index;
                size_t doc_size = (*inverted_index.get_docs())[index].words_sum;
                size_t word_nums_in_all_docs = inverted_index.get_word_locations(*it)->get_sum();
                size_t all_words_sum = inverted_index.GetAllWordsSum();
                if (scores.count(index) == 0) {
                    scores[index] = estimator.Score(it2->word_nums, doc_size, word_nums_in_all_docs, all_words_sum);
                } else {
                    scores[index] += estimator.Score(it2->word_nums, doc_size, word_nums_in_all_docs, all_words_sum);
                }
            }
        }

        // 6.
        vector<pair<size_t, double> > results(scores.begin(), scores.end());
        sort(results.begin(), results.end(), cmp);
        size_t l = (results.size() > 10 ? 10 : results.size());
        cout << "Answer(s): (ranking according to relevance)" << endl;
        for (size_t i = 0; i < l; ++i) {
            cout << "Document index: " << results[i].first << endl;
        }

        cout << endl << "Please input your query: ";
    }

    return 0;
}
