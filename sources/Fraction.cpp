//
// Created by Lara Abu Hamad on 15/04/2023.
//

#include "Fraction.hpp"
using namespace std;

namespace ariel{
    Fraction::Fraction(): numerator(0), denominator(1) {
        Fraction::numerator = 0;
        Fraction::denominator = 1;
    }
    Fraction::Fraction(int numerator): numerator(numerator), denominator(1) {
        Fraction::numerator = numerator;
        Fraction::denominator = 1;
    }
    Fraction::Fraction(double x) {
        numerator = int(x);
        denominator = 1;
        if(x < 0){
            numerator *= -1;
            x *= -1;
        }
        x = x-numerator;
        while(x > 0){
            denominator *= 10;
            int y = x*10;
            numerator = numerator*10 + y;
            x = x-numerator;
        }
    }
    Fraction::Fraction(int numerator, int denominator): numerator(numerator), denominator(denominator) {
        if(denominator == 0)
            throw invalid_argument("Division by 0");
        Fraction::numerator = numerator;
        Fraction::denominator = denominator;
    }
    Fraction::operator string() const {
        return to_string(numerator) + "/" + to_string(denominator);
    }
}