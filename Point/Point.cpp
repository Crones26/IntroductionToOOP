#include"Point.h"

double Point::get_x() const
{
	return x;
}

double Point::get_y() const
{
	return y;
}

void Point::set_x(double x)
{
	this->x = x;
}

void Point::set_y(double y)
{
	this->y = y;
}

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
	cout << "DoubleArgConst\t" << this << endl;
}
Point::Point(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
	cout << "copyConstr\t" << this << endl;
}
Point::~Point()
{
	cout << "Destructor\t" << this << endl;
}

void Point::print() const
{
	cout << "x = " << x << "\tY = " << y << endl;
}

double Point::distance(const Point& B) const
{
	//this->x *= 10;
	return sqrt((pow((B.get_x() - this->x), 2)) + (pow((B.get_y() - this->y), 2)));
}

Point& Point::operator=(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
	cout << "operator=\t" << this << endl;

	return *this;
}

Point& Point::operator++()
{
	this->x++;
	this->y++;

	return *this;
}

Point Point::operator++(int)
{
	Point old = *this;
	this->x++;
	this->y++;

	return old;
}

double distance(const Point& A, const  Point& B)
{
	return sqrt((pow((B.get_x() - A.get_x()), 2)) + (pow((B.get_y() - A.get_y()), 2)));
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());

	return result;
}

bool operator==(const Point& left, const Point& right)
{
	return (left.get_x() == right.get_x() && left.get_y() == right.get_y());
}

std::ostream& operator<<(std::ostream& os, const Point& obj)
{
	return os << "X = " << obj.get_x() << "\tY = " << obj.get_y() << endl;
}