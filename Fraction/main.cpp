#include"Fraction.h"
#define delimiter "\n--------------------------------------------\n"

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define INCREMENT_AND_DECREMENT_OPERATORS

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

#ifdef ARITHMETICAL_OPERATORS_CHECK

    Fraction C = A * B;
    C.print();

    Fraction D = A / B;
    D.print();

    Fraction E = A + B;
    E.print();

    Fraction F = A - B;
    F.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef INCREMENT_AND_DECREMENT_OPERATORS
    cout << "increment and decrement operators:" << endl;
    a.to_proper().print();
    ++a;
    a.print();
    a++;
    a.print();
    --a;
    a.print();
    a--;
    a.print();

#endif // INCREMENT_AND_DECREMENT_OPERATORS

}