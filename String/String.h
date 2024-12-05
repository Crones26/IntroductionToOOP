#pragma once

#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n--------------------------------------------\n"

//////////////////////////////////////////////////////////
//			ОБЪЯВЛЕНИЕ КЛаССа(Class Declaration)		//

class String;
std::ostream& operator<<(std::ostream& os, const String& obj);
String operator+(const String& left, const String& right);

class String
{
	int	size;  //Размер строки в байтах
	char* str; //Указатель на строку в динамической памяти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//				Constructors:
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other) noexcept;
	~String();

	//				Operators:
	String& operator=(const String& other);
	String& operator=(String&& other) noexcept;
	//				Indexing operators:
	char& operator[](int index) const;
	char& operator[](int index);
	//				Methods:
	void print()const;

};

