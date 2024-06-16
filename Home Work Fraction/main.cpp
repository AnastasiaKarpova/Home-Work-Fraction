#include <iostream>

using namespace std;

using std::cin;
using std::cout;
using std::endl;

class Fraction
{
	int integer; 
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numenator)
	{
		this->numerator = numenator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	Fraction()
	{
		integer = 0;
		numerator = 0;
		set_denominator(1);
		cout << "DefaultConstraction:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		set_denominator(1);
		cout << "SingleArgumentConstraction:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constractor:\t\t" << this << endl;
	}
	Fraction(int integer = 0, int numerator = 0, int denominator = 1)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	void print()const
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
};

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

void main()
{
	setlocale(LC_ALL, "");

	Fraction A(2, 3, 4);
	A.print();
	Fraction B(3, 4, 5);
	B.print();
	A.to_improper().print();
	A.to_proper().print();

	Fraction C = A * B;
	C.print();
	Fraction D = A + B;
	D.print();
	Fraction E = A - B;
	E.print();
	Fraction F = A / B;
	F.print();
	cout << (A == B) << endl;
}