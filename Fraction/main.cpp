#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n---------------------------------------\n"

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
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}
	//					Constructors
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Default Constructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgumentConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "TwoArgumentConstructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "ThreeArgumentConstructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	/*Fraction(double decimal)
	{
		integer = decimal; 
		double fractional = decimal - integer;
		denominator = 1;
		while (fractional - int(fractional) != 0.0 && denominator <= 100000000)
		{
			fractional *= 10;
			denominator *= 10;
		}
		numerator = fractional;
		reduce();
		cout << "DoubleArgumentConstructor:\t" << this << endl;
	}*/

	/*Fraction(double decimal)
	{
		integer = decimal;
		double fractional = decimal - integer;
		const int precision = 100000000;
		numerator = (fractional * precision);
		denominator = precision;
		reduce(); 
		cout << "DoubleArgumentConstructor:\t" << this << endl;
	}*/

	Fraction(double decimal)
	{
		decimal += 1e-10;
		integer = decimal;
		decimal -= integer; 
		denominator = 1e+9;
		numerator = decimal * denominator;
		reduce();
		cout << "DoubleArgumentConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//					Operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}
	//				Type-cast operators
	explicit operator int()
	{
		return to_proper().integer;
		//to_proper();
		//return integer;
	}
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	Fraction& operator++()
	{
		this->integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()
	{
		this->integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}

	//					Methods
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
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
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
		int GCD = more; //GCD - Greatest Common Divisor
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	void print()const
	{
		if (integer) cout << integer;
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}
};
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;*/
	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
	result.to_proper();
	return result;*/

	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		(left.get_numerator() * (right.get_denominator()) + right.get_numerator() * (left.get_denominator())),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		(left.get_numerator() * (right.get_denominator()) - right.get_numerator() * (left.get_denominator())),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
//					Comparison operators:
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
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
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction& left, const  Fraction& right)
{
	return !(left < right);
}
bool operator<=(const Fraction& left, const  Fraction& right)
{
	return !(left > right);
}
//					Input Output Operators
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
//{
//	int integer, numerator, denominator;
//	is >> integer >> numerator >> denominator;
//	obj.set_integer(integer);
//	obj.set_numerator(numerator);
//	obj.set_denominator(denominator);
//	return is;
//}
{
	const int SIZE = 256;
	char buffer[SIZE] = {};
	//is >> buffer;
	is.getline(buffer, SIZE);

	int number[3] = {};
	int n = 0;
	const char delimiters[] = " /()";
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters)) {
		number[n++] = atoi(pch);
	}
	for (int i = 0; i < n; i++) 
	{
		cout << number[i] << "\t";
	}
	cout << endl;

	switch (n)
	{
	case 1:obj = Fraction(number[0]); break;
	case 2:obj = Fraction(number[0],number[1]); break;
	case 3:obj = Fraction(number[0],number[1], number[2]); break;
	}
	return is;
}

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define IOSTREAM_CHECK
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_HOME_WORK
void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;			
	A.print();

	Fraction B = 6;		
	B.print();

	Fraction C(1, 16);	
	C.print();

	Fraction D(4, 6, 9);
	D.print();

	Fraction E = C;		
	E.print();

	Fraction F;			
	F = D;
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	A.print();
	Fraction B(3, 4, 5);
	B.print();

	/*Fraction C = A / B;
	C.print();*/

	A *= B;
	A.print();
	A /= B;
	A.print();
	A += B;
	A.print();
	A -= B;
	A.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef IOSTREAM_CHECK

	//cout << (Fraction(1, 3) == Fraction(5, 11)) << endl;
	//cout << (Fraction(1, 3) != Fraction(5, 11)) << endl;
	//cout << (Fraction(1, 3) >= Fraction(5, 11)) << endl;
	//cout << (Fraction(1, 3) <= Fraction(5, 11)) << endl;
	//cout << (Fraction(1, 3) > Fraction(5, 11)) << endl;
	//cout << (Fraction(1, 3) < Fraction(5, 11)) << endl;

	Fraction A;
	cout << "Введите числа для вывода на экран: "; cin >> A;
	cout << A << endl;

#endif // IOSTREAM_CHECK

#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5;
	cout << A << endl;
	cout << delimiter << endl;

	Fraction B;
	cout << delimiter << endl;
	B = Fraction (8);
	cout << delimiter << endl;
	cout << B << endl;
	cout << delimiter << endl;
#endif // CONVERSION_FROM_OTHER_TO_CLASS

#ifdef CONVERSIONS_HOME_WORK
	Fraction A = 2.76;
	cout << A << endl;
#endif // CONVERSIONS_HOME_WORK

	Fraction A(2, 3, 4);
	A.to_improper();
	cout << A << endl;
	
	int a = int(A);
	cout << a << endl;
	cout << A << endl;

	double da = double(A);
	cout << da << endl;
}