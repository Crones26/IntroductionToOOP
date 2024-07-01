#include"Point.h"

#define delimiter "\n--------------------------\n"

//#define STRUCT_POINT
//#define CONSTRUCTORS_CHECK
//#define DISTANCE_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#if defined STRUCT_POINT
	Point A;
	A.x = 2;
	A.y = 3;

	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;

	cout << pA->x << "\t" << pA->y << endl;
#endif

#if defined CONSTRUCTORS_CHECK
	Point A;
	//A.set_x(2);
	//A.set_y(3);	
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	/*for (int i = 0; i < 10; ++i)
	{
		cout << i << "\t";
	}*/

	Point B = 5;
	B.print();

	Point C(2, -5);
	//Point D(-4, 3);
	Point D = C;
	C.print();
	D.print();

	Point E;
	E = D;
	E.print();

	//cout << "distanceToPoint = " << C.distance(D) << endl;
	//cout << "distanceBetweenPoints = " << distance(C, D) << endl;

#endif

#if defined DISTANCE_CHECK
	Point A(2, 3);
	Point B(7, 8);

	A.print();
	B.print();

	cout << delimiter << endl;
	cout << "distance from A to B " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "distance from B to A " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "distance between A & B " << distance(A, B) << endl;
	cout << delimiter << endl;

#endif

#if defined ASSIGNMENT_CHECK

	int a;
	int b;
	int c;

	a = b = c = 0;

	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;

	cout << delimiter << endl;

	A = B = C = Point(2, 3); //Point(2, 3) - явный вызов конструктора 
	//И создается временный безымянный объект
	//этот объект и передается как параметр 
	//в первый оператор оператор присваивания

	cout << delimiter << endl;

	A.print();
	B.print();
	C.print();

	cout << delimiter << endl;

#endif

#ifdef ARITHMETICAL_OPERATORS_CHECK

	Point A(2, 3);
	A.print();

	Point B(7, 8);
	B.print();

	Point C = A + B;
	C.print();

	//++C;
	Point D = C++;
	C.print();
	D.print();

#endif 

#ifdef COMPARISON_OPERATORS_CHECK

	//cout << (2 == 3) << endl;
	Point A(2, 3);
	Point B(7, 8);
	cout << (A == B) << endl;
	//cout << (Point(2, 3) == Point(3, 3)) << endl;  

#endif 

	Point A(2, 3);

	cout << A << endl;
}