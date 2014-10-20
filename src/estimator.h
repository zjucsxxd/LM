#ifndef ESTIMATOR__H
#define ESTIMATOR__H

class Estimator {
private:
    double lambda;
public:
    void set_lambda(double);
    double Score(size_t, size_t, size_t, size_t);
};

#endif