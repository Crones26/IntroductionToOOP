#pragma once
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n--------------------------------------------\n"

class Point;
double distance(const Point& A, const  Point& B);
Point operator+(const Point& left, const Point& right);
bool operator==(const Point& left, const Point& right);
std::ostream& operator<<(std::ostream& os, const Point& obj);

class Point
{
private:

	double x;
	double y;

public:

	double get_x() const;
	double get_y() const;
	void set_x(double x);
	void set_y(double y);

	Point(double x = 0, double y = 0);
	Point(const Point& other);
	~Point();

	void print() const;
	double distance(const Point& B) const;

	Point& operator=(const Point& other);
	Point& operator++();
	Point operator++(int);
};