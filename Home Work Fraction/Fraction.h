#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

using std::cin;
using std::cout;
using std::endl;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numenator);
	void set_denominator(int denominator);

	Fraction();
	Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(double decimal);
	~Fraction();

	Fraction& to_improper();
	Fraction& to_proper();
	Fraction& reduce();
	void print()const;
};
