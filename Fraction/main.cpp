#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Fraction
{
    int integer;        // Целая часть
    int numerator;      // Числитель
    int denominator;    // Знаменатель

public:
    int get_integer() const
    {
        return integer;
    }
    int get_numerator() const
    {
        return numerator;
    }
    int get_denominator() const 
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
    //              Конструкторы
    Fraction() : integer(0), numerator(0), denominator(1)
    {
        cout << "DefaultConstructor:\t" << this << endl;
    }
    Fraction(int integer) : integer(integer), numerator(0), denominator(1)
    {
        cout << "SingleArgumentConstructor:\t" << this << endl;
    }
    Fraction(int numerator, int denominator) : integer(0), numerator(numerator)
    {
        set_denominator(denominator);
        cout << "TwoArgumentConstructor:\t" << this << endl;
    }
    Fraction(int integer, int numerator, int denominator) : integer(integer), numerator(numerator)
    {
        set_denominator(denominator);
        cout << "ThreeArgumentConstructor:\t" << this << endl;
    }
    Fraction(const Fraction& other) : integer(other.integer), numerator(other.numerator), denominator(other.denominator)
    {
        cout << "CopyConstructor:\t" << this << endl;
    }
    ~Fraction()
    {
        cout << "Destructor:\t" << this << endl;
    }
    //               Методы
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
    void print() const
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

    //               Операторы
    Fraction& operator=(const Fraction& other)
    {
        if (this != &other)
        {
            this->integer = other.integer;
            this->numerator = other.numerator;
            this->denominator = other.denominator;
        }
        return *this;
    }
    // Инкременты
   Fraction& operator++()
   {
       integer++;
       return *this;
   }
   Fraction operator++(int)
   {
       Fraction old = *this;
       integer++;
       return old;
   }
   // Декременты
   Fraction& operator--()
   {
       integer--;
       return *this;
   }
   Fraction operator--(int)
   {
       Fraction old = *this;
       integer--;
       return old;
   }
};
//              Перегруженные операторы
Fraction operator*(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();
    Fraction result;
    result.set_numerator(left.get_numerator() * right.get_numerator());
    result.set_denominator(left.get_denominator() * right.get_denominator());
    return result.to_proper();
}
Fraction operator/(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();
    Fraction result;
    result.set_numerator(left.get_numerator() * right.get_denominator());
    result.set_denominator(left.get_denominator() * right.get_numerator());
    return result.to_proper();
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

//#define CONSTRUCTORS_CHECK

void main()
{
    setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
    Fraction A;		// Default constructor
    A.print();

    Fraction B = 5; // Single-argument constructor
    B.print();

    Fraction C(1, 2);
    C.print();

    Fraction D(2, 3, 4);
    D.print();
#endif // CONSTRUCTORS_CHECK

    Fraction A(2, 3, 4);
    A.print();
    Fraction B(3, 4, 5);
    B.print();
    A.to_improper().print();
    A.to_proper().print();

    Fraction C = A * B;
    C.print();
    
    Fraction D = A / B;
    D.print();

    Fraction E = A + B;
    E.print();

    Fraction F = A - B;
    F.print();

    cout << "Increment and Decrement operators:" << endl;
    A.to_proper().print();
    ++A;
    A.print();
    A++;
    A.print();
    --A;
    A.print();
    A--;
    A.print();

}