#include"Fraction.h"

int Fraction::get_integer() const
{
    return this->integer;
}
int Fraction::get_numerator() const
{
    return this->numerator;
}
int Fraction::get_denominator() const
{
    return this->denominator;
}

void Fraction::set_integer(int integer)
{
    this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
    this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
    if (denominator == 0)denominator = 1;
    this->denominator = denominator;
}

//                 Constructors
Fraction::Fraction()
{
    integer = 0;
    numerator = 0;
    set_denominator(1);
    cout << "defaultConstr\t" << this << endl;
}
Fraction::Fraction(int integer)
{
    this->integer = integer;
    this->numerator = 0;
    set_denominator(1);
    cout << "singleArgConstructor\t" << this << endl;
}
Fraction::Fraction(double decimal)
{
    decimal += 1e-10;
    this->integer = decimal;
    decimal -= integer;
    this->denominator = 1e+9;
    this->numerator = decimal * this->denominator;
    reduce();
    cout << "doubleConstructor\t" << this << endl;
}
Fraction::Fraction(int numerator, int denominator)
{
    this->integer = 0;
    this->numerator = numerator;
    set_denominator(denominator);
    cout << "constructor\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
    set_integer(integer);
    set_numerator(numerator);
    set_denominator(denominator);
    cout << "constructor\t" << this << endl;
}
Fraction::Fraction(const Fraction& other)
{
    this->integer = other.integer;
    this->numerator = other.numerator;
    this->denominator = other.denominator;
    cout << "copyConstructor\t" << this << endl;
}
Fraction::~Fraction()
{
    cout << "destructor\t" << this << endl;
}

//                  Operators
Fraction& Fraction::operator=(const Fraction& other)
{
    this->integer = other.integer;
    this->numerator = other.numerator;
    this->denominator = other.denominator;
    cout << "copyAssignment\t" << this << endl;
    return *this;
}
Fraction& Fraction::operator*=(Fraction& other)
{
    return *this = *this * other;
}
Fraction& Fraction::operator/=(Fraction& other)
{
    return *this = *this / other;
}
Fraction::operator int()
{
    //to_proper();
    //return integer;
    return to_proper().integer;
}
Fraction::operator double()const
{
    return integer + (double)numerator / (double)denominator;
}

//                  Methods
Fraction& Fraction::to_improper()
{
    this->numerator += this->integer * this->denominator;
    integer = 0;
    return *this;
}
Fraction& Fraction::to_proper()
{
    this->integer += this->numerator / this->denominator;
    this->numerator %= this->denominator;
    return *this;
}
Fraction Fraction::inverted() const
{
    Fraction inverted = *this;
    inverted.to_improper();
    swap(inverted.numerator, inverted.denominator);
    return inverted;
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
void Fraction::print() const
{
    if (integer)cout << integer;
    if (numerator != 0)
    {
        if (integer)cout << "(";
        cout << numerator << "/" << denominator;
        if (integer)cout << ")";
    }
    else if (integer == 0)cout << 0;
    cout << endl;
}

Fraction operator*(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();
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
    Fraction result;
    result.set_numerator(left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator());
    result.set_denominator(left.get_denominator() * right.get_denominator());
    return result.to_proper();
}
Fraction operator-(Fraction& left, Fraction& right)
{
    Fraction result;
    left.to_improper();
    right.to_improper();
    result.set_numerator((left.get_numerator() * right.get_denominator()) - (right.get_numerator() * left.get_denominator()));
    result.set_denominator(left.get_denominator() * right.get_denominator());
    return result.to_proper();
}

//              Comparison operators
bool operator==(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();
    return
        left.get_numerator() * right.get_denominator() ==
        right.get_numerator() * left.get_denominator();
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
    if (obj.get_integer())os << obj.get_integer();
    if (obj.get_numerator())
    {
        if (obj.get_integer())os << "(";
        os << obj.get_numerator() << "/" << obj.get_denominator();
        if (obj.get_integer())os << ")";
    }
    else if (obj.get_integer() == 0)os << 0;
    return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
    const int SIZE = 256;
    char buffer[SIZE] = {};
    is.getline(buffer, SIZE);

    int numbers[3] = {};
    int n = 0;
    const char delimiters[] = " /()";
    for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
        numbers[n++] = atoi(pch);
    switch (n)
    {
    case 1: obj = Fraction(numbers[0]); break;
    case 2: obj = Fraction(numbers[0], numbers[1]); break;
    case 3: obj = Fraction(numbers[0], numbers[1], numbers[2]); break;
    }
    return is;
    
}