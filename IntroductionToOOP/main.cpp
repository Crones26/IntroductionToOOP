﻿#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n--------------------------------------------\n"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;

	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignmet:\t\t" << this << endl;
		return *this;
	}
	double distance(const Point& other) const
	{
		double dx = this->x - other.x;
		double dy = this->y - other.y;
		double distance = sqrt(dx * dx + dy * dy);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};
double distance(const Point& A, const Point& B)
{
	double dx = B.get_x() - A.get_x();
	double dy = B.get_y() - A.get_y();
	return sqrt(dx * dx + dy * dy);
}
//#define STRUCT_POINT
//#define CONSTRUCTORS_CHECK
//#define DISTANCE_CHEK
//#define ASSIGNMENT_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	Point A;
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef CONSTRUCTORS_CHECK
	 Point A;
    cout << A.get_x() << "\t" << A.get_y() << endl;
    A.print();

    Point B = 5;
    B.print();

    Point C(2, 3);
    C.print();

    Point D = C; // Вызов конструктора копирования
    D.print();

    Point E;
    E = D; // Вызов оператора присваивания
    E.print();

#endif // CONSTRUCTORS_CHECK

#ifdef DISTANCE_CHEK
	Point A(2, 3);
	Point B(7, 8);

	A.print();
	B.print();

	cout << delimiter << endl;
	cout << "Расстояние от точки 'A' до точки 'B': " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'B' до точки 'A': " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'A' и 'B':  " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'B' и 'A':  " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHEK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;
	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();
	cout << delimiter << endl;
#endif // ASSIGNMENT_CHECK

}
