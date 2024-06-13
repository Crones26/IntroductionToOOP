#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

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

	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	double distance(const Point& other) const
	{
		double dx = other.x - this->x;
		double dy = other.y - this->y;
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

void main()
{
	setlocale(LC_ALL, "");

	Point A(2, 3);
	Point B(7, 8);

	A.print();
	B.print();

	cout << "Расстояние от A до B:   " << A.distance(B) << endl;
	cout << "Расстояние между A и B: " << distance(A, B) << endl;
}