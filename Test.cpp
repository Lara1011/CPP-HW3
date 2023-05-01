//
// Created by Lara Abu Hamad on 01/05/2023.
//

#include "doctest.h"
#include "Fraction.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("Initialization") {
    CHECK_NOTHROW(Fraction{10, 11});

    Fraction f1(10, 11);
    CHECK(f1.getNumerator() == 10);
    CHECK(f1.getDenominator() == 11);

    Fraction f2(3.4);
    CHECK(f2.getNumerator() == 17);
    CHECK(f2.getDenominator() == 5);

    // Division by zero.
    CHECK_THROWS(Fraction {1, 0});
}

TEST_CASE("+ operator"){
    Fraction a(1, 3);
    Fraction b(3, 4);

    Fraction c = a + b;
    CHECK(c.getNumerator() == 13);
    CHECK(c.getDenominator() == 12);

    Fraction d = a + 2.6;
    CHECK(d.getNumerator() == 44);
    CHECK(d.getDenominator() == 15);

    Fraction e = 0.4 + b;
    CHECK(e.getNumerator() == 23);
    CHECK(e.getDenominator() == 20);

    Fraction f = d + e;
    CHECK(f.getNumerator() == 49);
    CHECK(f.getDenominator() == 12);
}

TEST_CASE("- operator"){
    Fraction a(1, 3);
    Fraction b(3, 4);

    Fraction c = b - a;
    CHECK(c.getNumerator() == 5);
    CHECK(c.getDenominator() == 12);

    Fraction d = a - 2.6;
    CHECK(d.getNumerator() == -34);
    CHECK(d.getDenominator() == 15);

    Fraction e = b - 0.4;
    CHECK(e.getNumerator() == 7);
    CHECK(e.getDenominator() == 20);

    Fraction f = d - e;
    CHECK(f.getNumerator() == -157);
    CHECK(f.getDenominator() == 60);
}

TEST_CASE("* operator"){
    Fraction a(1, 3);
    Fraction b(3, 4);

    Fraction c = a * b;
    CHECK(c.getNumerator() == 1);
    CHECK(c.getDenominator() == 4);

    Fraction d = a * 2.6;
    CHECK(d.getNumerator() == 13);
    CHECK(d.getDenominator() == 15);

    Fraction e = 0.4 * b;
    CHECK(e.getNumerator() == 3);
    CHECK(e.getDenominator() == 10);

    Fraction f = d * e;
    CHECK(f.getNumerator() == 13);
    CHECK(f.getDenominator() == 50);
}

TEST_CASE("/ operator"){
    Fraction a(1, 3);
    Fraction b(3, 4);

    Fraction c = a / b;
    CHECK(c.getNumerator() == 4);
    CHECK(c.getDenominator() == 9);

    Fraction d = a / 2.6;
    CHECK(d.getNumerator() == 5);
    CHECK(d.getDenominator() == 39);

    Fraction e = 0.4 / b;
    CHECK(e.getNumerator() == 8);
    CHECK(e.getDenominator() == 15);

    Fraction f = d / e;
    CHECK(f.getNumerator() == 25);
    CHECK(f.getDenominator() == 104);
}

TEST_CASE("> operator"){
    Fraction f(11, 3);
    CHECK(f > 2);
    CHECK(f > 0);

    CHECK(f > Fraction {2, 3});
    CHECK(f > Fraction {3});
    CHECK(f > Fraction {1.0});
    CHECK(f > Fraction {2.2});
}

TEST_CASE("< operator"){
    Fraction f(11, 3);
    CHECK(f < 4);
    CHECK(f < 5);

    CHECK(f < Fraction {10, 2});
    CHECK(f < Fraction {7, 1});
    CHECK(f < Fraction {3.9});
    CHECK(f < Fraction {5.77});
}

TEST_CASE(">= operator"){
    Fraction f(11, 3);
    CHECK(f >= 2);
    CHECK(f >= 0);

    CHECK(f >= Fraction {2, 3});
    CHECK(f >= Fraction {3});
    CHECK(f >= Fraction {1.0});
    CHECK(f >= Fraction {2.2});
    CHECK(f >= Fraction {11, 3});
    CHECK(f >= 3.66666666666);
}

TEST_CASE("<= operator"){
    Fraction f(11, 3);
    CHECK(f <= 4);
    CHECK(f <= 5);

    CHECK(f <= Fraction {10, 2});
    CHECK(f <= Fraction {7, 1});
    CHECK(f <= Fraction {3.9});
    CHECK(f <= Fraction {5.77});
    CHECK(f <= Fraction {11, 3});
    CHECK(f <= 3.666666667);
}

TEST_CASE("!= operator"){
    Fraction f(11, 3);
    CHECK(f != 4);
    CHECK(f != 5);

    CHECK(f != Fraction {10, 2});
    CHECK(f != Fraction {7, 1});
    CHECK(f != Fraction {3.9});
    CHECK(f != Fraction {5.77});
    CHECK(f != 3.6666666667);
}

TEST_CASE("== operator"){
    Fraction f(11, 3);
    CHECK(f == Fraction {11, 3});
    CHECK(f == Fraction {22, 6});
    CHECK(f == Fraction {33, 9});
    CHECK(f == Fraction {44, 12});
    CHECK(f == Fraction {55, 15});
    CHECK(f == Fraction {66, 18});
    CHECK(f == Fraction {77, 21});
    CHECK(f == Fraction {88, 24});
    CHECK(f == Fraction {99, 27});
    cout << f.operator double() << " " << 11.0/3.0 << "\n";
    CHECK(f.operator double() == 11.0/3.0);
}

TEST_CASE("Input stream") {
    std::istringstream iss("3/4");
    Fraction f;
    iss >> f;
    CHECK(f.getNumerator() == 3);
    CHECK(f.getDenominator() == 4);

    std::istringstream iss2("5/0");
    CHECK_THROWS_AS(iss2 >> f, std::invalid_argument);
}

TEST_CASE("Output stream") {
    Fraction f(3, 4);
    std::ostringstream oss;
    oss << f;
    CHECK(oss.str() == "3/4");
}