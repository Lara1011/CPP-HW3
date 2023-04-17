//
// Created by Lara Abu Hamad on 15/04/2023.
//

#include "Fraction.hpp"
using namespace std;

namespace ariel{
    Fraction::Fraction(): numerator(0), denominator(1) {}

    Fraction::Fraction(int numerator): numerator(numerator), denominator(1) {}

    Fraction::Fraction(double x) {
        numerator = int(x);
        denominator = 1;
        x = (x - numerator) * 10;
        while(denominator < 1000 && x != 0){
            denominator *= 10;
            numerator = numerator*10 + int(x);
            x = (x - int(x)) * 10;
        }
    }

    Fraction::Fraction(int numerator, int denominator): numerator(numerator), denominator(denominator) {
        if(denominator == 0)
            throw invalid_argument("Division by 0");
    }

     int Fraction::gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void Fraction::reduce() {
        int gcd = abs(Fraction::gcd(numerator, denominator));
        numerator /= gcd;
        denominator /= gcd;
    }

    Fraction operator+(const Fraction& left, const Fraction& right) {
        int numer = (left.numerator * right.denominator) + (right.numerator * left.denominator);
        int denom = left.denominator * right.denominator;
        int gcd = Fraction::gcd(numer, denom);
        numer /= gcd;
        denom /= gcd;
        return Fraction(numer, denom);
    }

    Fraction operator-(const Fraction& left, const Fraction& right) {
        int numer = (left.numerator * right.denominator) - (right.numerator * left.denominator);
        int denom = left.denominator * right.denominator;
        int gcd = Fraction::gcd(numer, denom);
        numer /= gcd;
        denom /= gcd;
        return Fraction(numer, denom);
    }

    Fraction operator*(const Fraction& left, const Fraction& right) {
        int numer = left.numerator * right.numerator;
        int denom = left.denominator * right.denominator;
        int gcd = Fraction::gcd(numer, denom);
        numer /= gcd;
        denom /= gcd;
        return Fraction(numer, denom);
    }

    Fraction operator/(const Fraction& left, const Fraction& right) {
        int numer = left.numerator * right.denominator;
        int denom = left.denominator * right.numerator;
        int gcd = Fraction::gcd(numer, denom);
        numer /= gcd;
        denom /= gcd;
        return Fraction(numer, denom);
    }

//    Fraction Fraction::operator+(const double &d) {
//        return Fraction(*this + d);
//    }
//
//    Fraction Fraction::operator-(const double &d) {
//        return Fraction(*this - d);
//    }
//
//    Fraction Fraction::operator*(const double &d) {
//        return Fraction(*this * d);
//    }
//
//    Fraction Fraction::operator/(const double &d) {
//        return Fraction(*this / d);
//    }
//
//    Fraction Fraction::operator+(const int& i) {
//        return Fraction(*this + i);
//    }
//
//    Fraction Fraction::operator-(const int& i) {
//        return Fraction(*this - i);
//    }
//
//    Fraction Fraction::operator*(const int& i) {
//        return Fraction(*this * i);
//    }
//
//    Fraction Fraction::operator/(const int& i) {
//        return Fraction(*this / i);
//    }

    Fraction operator+(const double &d, const Fraction &frac) {
        return Fraction(d) + frac;
    }

    Fraction operator-(const double &d, const Fraction &frac) {
        return Fraction(d) - frac;
    }

    Fraction operator*(const double &d, const Fraction &frac) {
        return Fraction(d) * frac;
    }

    Fraction operator/(const double &d, const Fraction &frac) {
        return Fraction(d) / frac;
    }

    Fraction operator+(const int &i, const Fraction &frac) {
        return Fraction(i) + frac;
    }

    Fraction operator-(const int &i, const Fraction &frac) {
        return Fraction(i) - frac;
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

//    bool Fraction::operator>(const Fraction &frac) const {
//        return *this > frac.operator double();
//    }
//
//    bool Fraction::operator<(const Fraction &frac) const {
//        return *this < frac.operator double();
//    }
//
//    bool Fraction::operator==(const Fraction &frac) const {
//        return *this == frac.operator double();
//    }
//
//    bool Fraction::operator!=(const Fraction &frac) const {
//        return *this != frac.operator double();
//    }
//
//    bool Fraction::operator>=(const Fraction &frac) const {
//        return *this >= frac.operator double();
//    }
//
//    bool Fraction::operator<=(const Fraction &frac) const {
//        return *this <= frac.operator double();
//    }

//    bool Fraction::operator>(const double& d) const {
//        return *this > d;
//    }
//
//    bool Fraction::operator<(const double& d) const {
//        return *this < d;
//    }
//
//    bool Fraction::operator==(const double& d) const {
//        return *this == d;
//    }
//
//    bool Fraction::operator!=(const double& d) const {
//        return *this != d;
//    }
//
//    bool Fraction::operator>=(const double& d) const {
//        return *this >= d;
//    }
//
//    bool Fraction::operator<=(const double& d) const {
//        return *this <= d;
//    }

    bool operator>(const Fraction& left, const Fraction& right){
        return left.operator double() > right.operator double();
    }

    bool operator<(const Fraction& left, const Fraction& right){
        return left.operator double() < right.operator double();
    }

    bool operator==(const Fraction& left, const Fraction& right){
        return left.operator double() == right.operator double();
    }

    bool operator!=(const Fraction& left, const Fraction& right){
        return left.operator double() != right.operator double();
    }

    bool operator>=(const Fraction& left, const Fraction& right){
        return left.operator double() >= right.operator double();
    }

    bool operator<=(const Fraction& left, const Fraction& right){
        return left.operator double() <= right.operator double();
    }

    bool operator>(const Fraction& frac, const double& d){
        return frac.operator double() > d;
    }

    bool operator<(const Fraction& frac, const double& d){
        return frac.operator double() < d;
    }

    bool operator==(const Fraction& frac, const double& d){
        return frac.operator double() == d;
    }

    bool operator!=(const Fraction& frac, const double& d){
        return frac.operator double() != d;
    }

    bool operator>=(const Fraction& frac, const double& d){
        return frac.operator double() >= d;
    }

    bool operator<=(const Fraction& frac, const double& d){
        return frac.operator double() <= d;
    }

    bool operator>(const Fraction& frac, const int& i){
        return frac.operator double() > i;
    }

    bool operator<(const Fraction& frac, const int& i){
        return frac.operator double() < i;
    }

    bool operator==(const Fraction& frac, const int& i){
        return frac.operator double() == i;
    }

    bool operator!=(const Fraction& frac, const int& i){
        return frac.operator double() != i;
    }

    bool operator>=(const Fraction& frac, const int& i){
        return frac.operator double() >= i;
    }

    bool operator<=(const Fraction& frac, const int& i){
        return frac.operator double() <= i;
    }

    bool operator>(const double& d, const Fraction& frac){
        return d > frac.operator double();
    }

    bool operator<(const double& d, const Fraction& frac){
        return d < frac.operator double();
    }

    bool operator==(const double& d, const Fraction& frac){
        return d == frac.operator double();
    }

    bool operator!=(const double& d, const Fraction& frac){
        return d != frac.operator double();
    }

    bool operator>=(const double& d, const Fraction& frac){
        return d >= frac.operator double();
    }

    bool operator<=(const double& d, const Fraction& frac){
        return d <= frac.operator double();
    }

    bool operator>(const int& i, const Fraction& frac){
        return i > frac.operator double();
    }

    bool operator<(const int& i, const Fraction& frac){
        return i < frac.operator double();
    }

    bool operator==(const int& i, const Fraction& frac){
        return i == frac.operator double();
    }

    bool operator!=(const int& i, const Fraction& frac){
        return i != frac.operator double();
    }

    bool operator>=(const int& i, const Fraction& frac){
        return i >= frac.operator double();
    }

    bool operator<=(const int& i, const Fraction& frac){
        return i <= frac.operator double();
    }



    Fraction::operator double() const {
        return double(numerator) / double(denominator);
    }

    Fraction::operator string() const {
        return to_string(numerator) + "/" + to_string(denominator);
    }
}