// Author: zhangfang
// Email: thuzhf@gmail.com

#include <cmath>

#include "estimator.h"

using namespace std;

double Estimator::Score(size_t word_nums_in_doc, size_t doc_size, size_t word_nums_in_all_docs, size_t all_words_sum) {
    double tmp1, tmp2, tmp;
    tmp1 = (word_nums_in_doc * 1.0 / doc_size);
    tmp2 = (word_nums_in_all_docs * 1.0 / all_words_sum);
    tmp = (1 / lambda - 1) * (tmp1 / tmp2);
    tmp = log(tmp + 1);
    return tmp;
}

void Estimator::set_lambda(double f) {
    lambda = f;
}
