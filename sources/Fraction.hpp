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
        static int gcd(int a, int b);
        void reduce();
    public:
        Fraction();
        Fraction(int numerator);
        Fraction(double x);
        Fraction(int numerator, int denominator);

        int getNumerator();
        void setNumerator();
        int getDenominator();
        void setDenominator();


        friend Fraction operator+(const Fraction& left, const Fraction& right);
        friend Fraction operator-(const Fraction& left, const Fraction& right);
        friend Fraction operator*(const Fraction& left, const Fraction& right);
        friend Fraction operator/(const Fraction& left, const Fraction& right);

//        Fraction operator+(const double& d);
//        Fraction operator-(const double& d);
//        Fraction operator*(const double& d);
//        Fraction operator/(const double& d);
//
//        Fraction operator+(const int& i);
//        Fraction operator-(const int& i);
//        Fraction operator*(const int& i);
//        Fraction operator/(const int& i);

        friend Fraction operator+(const double& d, const Fraction& frac);
        friend Fraction operator-(const double& d, const Fraction& frac);
        friend Fraction operator*(const double& d, const Fraction& frac);
        friend Fraction operator/(const double& d, const Fraction& frac);

        friend Fraction operator+(const int& i, const Fraction& frac);
        friend Fraction operator-(const int& i, const Fraction& frac);
        friend Fraction operator*(const int& i, const Fraction& frac);
        friend Fraction operator/(const int& i, const Fraction& frac);

        friend Fraction operator+(const Fraction& frac, const double& d);
        friend Fraction operator-(const Fraction& frac, const double& d);
        friend Fraction operator*(const Fraction& frac, const double& d);
        friend Fraction operator/(const Fraction& frac, const double& d);

        friend Fraction operator+(const Fraction& frac, const int& i);
        friend Fraction operator-(const Fraction& frac, const int& i);
        friend Fraction operator*(const Fraction& frac, const int& i);
        friend Fraction operator/(const Fraction& frac, const int& i);

//        bool operator>(const Fraction& frac) const;
//        bool operator<(const Fraction& frac) const;
//        bool operator==(const Fraction& frac) const;
//        bool operator!=(const Fraction& frac) const;
//        bool operator>=(const Fraction& frac) const;
//        bool operator<=(const Fraction& frac) const;

        friend bool operator>(const double& d, const Fraction& frac);
        friend bool operator<(const double& d, const Fraction& frac);
        friend bool operator==(const double& d, const Fraction& frac);
        friend bool operator!=(const double& d, const Fraction& frac);
        friend bool operator>=(const double& d, const Fraction& frac);
        friend bool operator<=(const double& d, const Fraction& frac);

        friend bool operator>(const int& i, const Fraction& frac);
        friend bool operator<(const int& i, const Fraction& frac);
        friend bool operator==(const int& i, const Fraction& frac);
        friend bool operator!=(const int& i, const Fraction& frac);
        friend bool operator>=(const int& i, const Fraction& frac);
        friend bool operator<=(const int& i, const Fraction& frac);

        friend bool operator>(const Fraction& frac, const double& d);
        friend bool operator<(const Fraction& frac, const double& d);
        friend bool operator==(const Fraction& frac, const double& d);
        friend bool operator!=(const Fraction& frac, const double& d);
        friend bool operator>=(const Fraction& frac, const double& d);
        friend bool operator<=(const Fraction& frac, const double& d);

        friend bool operator>(const Fraction& frac, const int& i);
        friend bool operator<(const Fraction& frac, const int& i);
        friend bool operator==(const Fraction& frac, const int& i);
        friend bool operator!=(const Fraction& frac, const int& i);
        friend bool operator>=(const Fraction& frac, const int& i);
        friend bool operator<=(const Fraction& frac, const int& i);

        friend bool operator>(const Fraction& left, const Fraction& right);
        friend bool operator<(const Fraction& left, const Fraction& right);
        friend bool operator==(const Fraction& left, const Fraction& right);
        friend bool operator!=(const Fraction& left, const Fraction& right);
        friend bool operator>=(const Fraction& left, const Fraction& right);
        friend bool operator<=(const Fraction& left, const Fraction& right);

        Fraction operator++();
        Fraction operator++(int);
        Fraction operator--();
        Fraction operator--(int);

        friend ostream& operator<<(ostream& out, const Fraction& frac);
        friend istream& operator>>(istream& in, Fraction& frac);
        //friend istream& operator<<(istream& in, Fraction& frac);

        operator double() const;
        operator string() const;
    };
}

#endif //CPP_HW3_FRACTION_H
