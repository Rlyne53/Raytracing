//
// Created by tmissing on 29/09/20.
//

#ifndef NORI_EQUATION_H
#define NORI_EQUATION_H

#include <vector>

class Equation {
public:
    virtual int hasSolution() = 0;
    virtual std::vector<float> getSolutions() = 0;
};
#endif //NORI_EQUATION_H
