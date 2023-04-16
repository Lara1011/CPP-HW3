//
// Created by Lara Abu Hamad on 15/04/2023.
//

#ifndef CPP_HW3_FRACTION_H
#define CPP_HW3_FRACTION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel {
    class Fraction {
    private:
        int numerator;
        int denominator;
    public:
        Fraction();
        Fraction(int numerator);
        Fraction(double x);
        Fraction(int numerator, int denominator);
        int getNumerator();
        void setNumerator();
        int getDenominator();
        void setDenominator();
        operator string() const;
    };
}

#endif //CPP_HW3_FRACTION_H
