// Author: zhangfang
// Email: thuzhf@gmail.com

#ifndef ESTIMATOR__H
#define ESTIMATOR__H

#include <iostream>

using namespace std;

class Estimator {
private:
    double lambda;
public:
    void set_lambda(double);
    double Score(size_t, size_t, size_t, size_t);
};

#endif
