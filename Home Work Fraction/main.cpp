#include "Fraction.h"

//#define ARITHMETICAL_OPERATORS_CHECK;
#define IOSTREAM_CHECK;
#define CONVERSIONS_HOME_WORK;

void main()
{
	setlocale(LC_ALL, "");

#ifdef ARITHMETICAL_OPERATORS_CHECK
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
#endif
#ifdef IOSTREAM_CHECK
	//cout << (Fraction(3, 5) == Fraction(4, 12)) << endl;
	//cout << (Fraction(3, 5) != Fraction(4, 12)) << endl;
	//cout << (Fraction(3, 5) >= Fraction(4, 12)) << endl;
	//cout << (Fraction(3, 5) <= Fraction(4, 12)) << endl;
	//cout << (Fraction(3, 5) > Fraction(4, 12)) << endl;
	//cout << (Fraction(3, 5) < Fraction(4, 12)) << endl;

	Fraction A(6, 9);
	cout << A << endl;

	Fraction B;
	cout << "¬ведите простую дробь: "; cin >> B;
	cout << B << endl;
#endif // IOSTREAM_CHECK

#ifdef CONVERSIONS_HOME_WORK
	Fraction A = 2.75;
	cout << A << endl;
#endif // CONVERSIONS_HOME_WORK
}