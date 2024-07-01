#include "Fraction.h"
#define delimiter "\n--------------------------------------------\n"

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define IOSTREAM_CHECK
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
#define CONVERSIONS_HOME_WORK


void main()
{
    setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK

    Fraction A;  //default constuctor
    A.print();

    Fraction B = 5; //single-arg constructor
    B.print();

    Fraction C(1, 2);
    C.print();

    Fraction D(2, 3, 4);
    D.print();

#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
    Fraction A(2, 3, 4);
    A.print();

    Fraction B(3, 4, 5);
    B.print();

    Fraction C = A * B;
    C.print();

    A *= B;
    A.print();
    A /= B;
    A.print();

#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef IOSTREAM_CHECK

    Fraction pupa;
    cout << (Fraction(1, 2) <= Fraction(5, 10)) << endl;
    cout << Fraction(1, 2) << endl;
    cin >> pupa;
    cout << pupa << endl;

#endif // IOSTREAM_CHECK

#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS

    Fraction A = (Fraction)5;
    cout << A << endl;

    cout << delimiter << endl;

    Fraction B;
    cout << delimiter << endl;
    B = Fraction(8);
    cout << delimiter << endl;
    cout << B << endl;

    cout << delimiter << endl;

#endif // CONVERSIONS_FROM_OTHER_TO_CLASS

}