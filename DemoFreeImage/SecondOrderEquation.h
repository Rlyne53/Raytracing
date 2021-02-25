#pragma once

#include <cmath>
#include "Equation.h"
#include <string>

class SecondOrderEquation : public Equation{

public:
    SecondOrderEquation(double a, double b, double c, double d) {
        if (a == 0) {
            throw std::string("this is not a second order equation");
        }
        _a = a;
        _b = b;
        _c = c-d;
        computeDelta();
    }

    int hasSolution() override {
        return numberOfSolutions>=1;
    }

    std::vector<float> getSolutions() override {
        std::vector<float> solutions(0);
        if (hasSolution()) {
            if (numberOfSolutions==1) {
                solutions.push_back(-_b/(2*_a));
            } else {
                solutions.push_back((-_b-sqrt(_delta))/(2*_a));
                solutions.push_back((-_b+sqrt(_delta))/(2*_a));
            }
        }
        return solutions;
    }

private:
    void computeDelta(){
        _delta = _b*_b - 4 *_a*_c;
        numberOfSolutions = _delta < 0 ? 0 : _delta > 0? 2 : 1 ;
    }

private:
    double _a;
    double _b;
    double _c;
    double _d;
    double _delta;
    int numberOfSolutions;
};