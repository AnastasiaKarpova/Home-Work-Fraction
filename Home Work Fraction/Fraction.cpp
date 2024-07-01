#include "Fraction.h"

int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numenator)
{
	this->numerator = numenator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0) denominator = 1;
	this->denominator = denominator;
}

Fraction::Fraction()
{
	integer = 0;
	numerator = 0;
	set_denominator(1);
	cout << "DefaultConstraction:\t" << this << endl;
}
Fraction::Fraction(int integer) :integer(integer), numerator(0)
{
	//this->integer = integer;
	//this->numerator = 0;
	set_denominator(1);
	cout << "SingleArgumentConstraction:\t" << this << endl;
}
Fraction::Fraction(int numerator, int denominator) : integer(0), numerator(numerator)
{
	//this->integer = 0;
	//this->numerator = numerator;
	set_denominator(denominator);
	cout << "Constractor:\t\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::Fraction(double decimal)
{
	integer = decimal;
	decimal -= integer;
	denominator = 1e+10;
	numerator = decimal * denominator;
	reduce();
	cout << "DoubleCOnstructor:\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t\t" << this << endl;
}

Fraction& Fraction::to_improper()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction& Fraction::to_proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction& Fraction::reduce()
{
	int more, less, rest;
	if (numerator > denominator)more = numerator, less = denominator;
	else less = numerator, more = denominator;
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more;
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}
void Fraction::print()const
{
	if (integer) cout << integer;
	if (numerator != 0)
	{
		if (integer) cout << "(";
		cout << numerator << "/" << denominator;
		if (integer) cout << ")";
	}
	else if (integer == 0) cout << 0;
	cout << endl;
}

Fraction operator*(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();

	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;
}
Fraction operator+(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();

	Fraction result;
	result.set_numerator((left.get_numerator() * right.get_denominator()) + (right.get_numerator() * left.get_denominator()));
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;
}
Fraction operator-(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_proper();

	Fraction result;
	result.set_numerator((left.get_numerator() * right.get_denominator()) - (right.get_numerator() * left.get_denominator()));
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;
}
Fraction operator/(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_proper();

	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_numerator());
	return result;
}
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_proper();

	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer()) os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer()) os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer()) os << ")";
	}
	else if (obj.get_integer() == 0) os << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	const int SIZE = 256;
	char buffer[SIZE] = {};
	is >> buffer;

	int numbers[3] = {};
	int n = 0;
	const char delimiters[] = " \()";
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		numbers[n++] = atoi(pch); // Функция atoi() принимает строку, и возвращает целочисленный аналог этой строки,
	//т.е., строку преобразует в число.
	for (int i = 0; i < n; i++) cout << numbers[i] << "\t"; cout << endl;
	switch (n)
	{
	case 1:obj = Fraction(numbers[0]); break;
	case 2:obj = Fraction(numbers[0], numbers[1]); break;
	case 3:obj = Fraction(numbers[0], numbers[1], numbers[2]); break;
	}
	return is;
}