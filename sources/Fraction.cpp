//
// Created by Lara Abu Hamad on 15/04/2023.
//

#include "Fraction.hpp"
#include <cmath>
using namespace std;

namespace ariel {
    Fraction::Fraction() : numerator(0), denominator(1) {}

    Fraction::Fraction(int numerator) : numerator(numerator), denominator(1) {}

    Fraction::Fraction(double number) {
        denominator = pow(10, 3);
        numerator = round(number * denominator);
        reduce();
    }

    Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
        if (denominator == 0)
            throw invalid_argument("Division by 0");
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }

    int Fraction::gcd(int first, int second) {
        return second == 0 ? first : gcd(second, first % second);
    }

    void Fraction::reduce() {
        int gcd = abs(Fraction::gcd(numerator, denominator));
        numerator /= gcd;
        denominator /= gcd;
    }

    int Fraction::getDenominator() {
        return this->denominator;
    }

    int Fraction::getNumerator() {
        return this->numerator;
    }

    void Fraction::setDenominator(int denom) {
        this->denominator = denom;
    }

    void Fraction::setNumerator(int numer) {
        this->numerator = numer;
    }

    Fraction operator+(const Fraction &left, const Fraction &right) {
        int numer = (left.numerator * right.denominator) + (right.numerator * left.denominator);
        int denom = left.denominator * right.denominator;
        int gcd = Fraction::gcd(numer, denom);
        numer /= gcd;
        denom /= gcd;
        if (denom < 0) {
            numer *= -1;
            denom *= -1;
        }
        return {numer, denom};
    }

    Fraction operator-(const Fraction &left, const Fraction &right) {
        int numer = (left.numerator * right.denominator) - (right.numerator * left.denominator);
        int denom = left.denominator * right.denominator;
        int gcd = Fraction::gcd(numer, denom);
        numer /= gcd;
        denom /= gcd;
        if (denom < 0) {
            numer *= -1;
            denom *= -1;
        }
        return {numer, denom};
    }

    Fraction operator*(const Fraction &left, const Fraction &right) {
        int numer = left.numerator * right.numerator;
        int denom = left.denominator * right.denominator;
        int gcd = Fraction::gcd(numer, denom);
        numer /= gcd;
        denom /= gcd;
        if (denom < 0) {
            numer *= -1;
            denom *= -1;
        }
        return {numer, denom};
    }

    Fraction operator/(const Fraction &left, const Fraction &right) {
        int numer = left.numerator * right.denominator;
        int denom = left.denominator * right.numerator;
        int gcd = Fraction::gcd(numer, denom);
        numer /= gcd;
        denom /= gcd;
        if (denom < 0) {
            numer *= -1;
            denom *= -1;
        }
        return {numer, denom};
    }

    Fraction operator+(const double &num, const Fraction &frac) {
        return Fraction(num) + frac;
    }

    Fraction operator-(const double &num, const Fraction &frac) {
        return Fraction(num) - frac;
    }

    Fraction operator*(const double &num, const Fraction &frac) {
        return Fraction(num) * frac;
    }

    Fraction operator/(const double &num, const Fraction &frac) {
        return Fraction(num) / frac;
    }

    Fraction operator+(const int &num, const Fraction &frac) {
        return Fraction(num) + frac;
    }

    Fraction operator-(const int &num, const Fraction &frac) {
        return Fraction(num) - frac;
    }

    Fraction operator*(const int &i, const Fraction &frac) {
        return Fraction(i) * frac;
    }

    Fraction operator/(const int &i, const Fraction &frac) {
        return Fraction(i) / frac;
    }

    Fraction operator+(const Fraction &frac, const double &d) {
        return frac + Fraction(d);
    }

    Fraction operator-(const Fraction &frac, const double &d) {
        return frac - Fraction(d);
    }

    Fraction operator*(const Fraction &frac, const double &d) {
        return frac * Fraction(d);
    }

    Fraction operator/(const Fraction &frac, const double &d) {
        return frac / Fraction(d);
    }

    Fraction operator+(const Fraction &frac, const int &i) {
        return frac + Fraction(i);
    }

    Fraction operator-(const Fraction &frac, const int &i) {
        return frac - Fraction(i);
    }

    Fraction operator*(const Fraction &frac, const int &i) {
        return frac * Fraction(i);
    }

    Fraction operator/(const Fraction &frac, const int &i) {
        return frac / Fraction(i);
    }

    bool operator>(const Fraction &left, const Fraction &right) {
        return left.operator double() > right.operator double();
    }

    bool operator<(const Fraction &left, const Fraction &right) {
        return left.operator double() < right.operator double();
    }

    bool operator==(const Fraction &left, const Fraction &right) {
        return left.operator double() == right.operator double();
    }

    bool operator!=(const Fraction &left, const Fraction &right) {
        return left.operator double() != right.operator double();
    }

    bool operator>=(const Fraction &left, const Fraction &right) {
        return left.operator double() >= right.operator double();
    }

    bool operator<=(const Fraction &left, const Fraction &right) {
        return left.operator double() <= right.operator double();
    }

    bool operator>(const Fraction &frac, const double &d) {
        return frac.operator double() > d;
    }

    bool operator<(const Fraction &frac, const double &d) {
        return frac.operator double() < d;
    }

    bool operator==(const Fraction &frac, const double &d) {
        return frac.operator double() == d;
    }

    bool operator!=(const Fraction &frac, const double &d) {
        return frac.operator double() != d;
    }

    bool operator>=(const Fraction &frac, const double &d) {
        return frac.operator double() >= d;
    }

    bool operator<=(const Fraction &frac, const double &d) {
        return frac.operator double() <= d;
    }

    bool operator>(const Fraction &frac, const int &i) {
        return frac.operator double() > i;
    }

    bool operator<(const Fraction &frac, const int &i) {
        return frac.operator double() < i;
    }

    bool operator==(const Fraction &frac, const int &i) {
        return frac.operator double() == i;
    }

    bool operator!=(const Fraction &frac, const int &i) {
        return frac.operator double() != i;
    }

    bool operator>=(const Fraction &frac, const int &i) {
        return frac.operator double() >= i;
    }

    bool operator<=(const Fraction &frac, const int &i) {
        return frac.operator double() <= i;
    }

    bool operator>(const double &num, const Fraction &frac) {
        return num > frac.operator double();
    }

    bool operator<(const double &num, const Fraction &frac) {
        return num < frac.operator double();
    }

    bool operator==(const double &num, const Fraction &frac) {
        return num == frac.operator double();
    }

    bool operator!=(const double &num, const Fraction &frac) {
        return num != frac.operator double();
    }

    bool operator>=(const double &num, const Fraction &frac) {
        return num >= frac.operator double();
    }

    bool operator<=(const double &num, const Fraction &frac) {
        return num <= frac.operator double();
    }

    bool operator>(const int &num, const Fraction &frac) {
        return num > frac.operator double();
    }

    bool operator<(const int &num, const Fraction &frac) {
        return num < frac.operator double();
    }

    bool operator==(const int &num, const Fraction &frac) {
        return num == frac.operator double();
    }

    bool operator!=(const int &num, const Fraction &frac) {
        return num != frac.operator double();
    }

    bool operator>=(const int &num, const Fraction &frac) {
        return num >= frac.operator double();
    }

    bool operator<=(const int &num, const Fraction &frac) {
        return num <= frac.operator double();
    }

    Fraction Fraction::operator++() {
        numerator += denominator;
        reduce();
        return *this;
    }

    const Fraction Fraction::operator++(int) {
        Fraction temp = *this;
        numerator += denominator;
        reduce();
        return temp;
    }

    Fraction Fraction::operator--() {
        numerator -= denominator;
        reduce();
        return *this;
    }

    const Fraction Fraction::operator--(int) {
        Fraction temp = *this;
        numerator -= denominator;
        reduce();
        return temp;
    }

    ostream &operator<<(ostream &out, const Fraction &frac) {
        out << frac.numerator << "/" << frac.denominator;
        return out;
    }

    istream &operator>>(istream &ins, Fraction &frac) {
        int numerator, denominator;
        char slash;
        ins >> numerator >> slash >> denominator;
        if (slash != '/')
            throw invalid_argument("Invalid input");
        if (ins)
            frac = Fraction(numerator, denominator);
        return ins;
    }

    Fraction::operator double() const {
        return double(numerator) / double(denominator);
    }

    Fraction::operator string() const {
        return to_string(numerator) + "/" + to_string(denominator);
    }
}