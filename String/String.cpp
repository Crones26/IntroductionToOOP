#include "String.h"

int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//				Constructors:
String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "DefaultConstructor:\t" << this << endl;
}
String::String(const char str[]) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};
	for (int i = 0; str[i]; i++)
	{
		this->str[i] = str[i];
	}
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	//this->size = other.size;
	//this->str = new char[size] {};
	/*for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}*/
	cout << "CopyConstructor:\t" << this << endl;
}
//			Move Constructor:
String::String(String&& other) noexcept :size(other.size), str(other.str) // r-value reference
{
	//Shallow copy:
	//this->size = other.size;
	//this->str = other.str;
	//Reset other:
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t\t" << this << endl;
}
//				Operators:
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}
//		Assignment operator by moving:
String& String::operator=(String&& other) noexcept
{
	if (this == &other) return *this;
	delete[] str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t\t" << this << endl;
	return *this;
}
//				Indexing operators:
char& String::operator[](int index) const
{
	return str[index];
}
char& String::operator[](int index)
{
	return str[index];
}
//				Methods:
void String::print()const
{
	cout << "Obj;\t\t\t" << this << endl;
	cout << "Size:\t\t\t" << size << endl;
	cout << "Addr:\t\t\t" << &str << endl;
	cout << "Str:\t\t\t" << str << endl;
	cout << delimiter << endl;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+(const String& left, const String& right)
{
	String buffer(left.get_size() + right.get_size() - 1);
	//buffer.print();
	for (int i = 0; i < left.get_size(); i++)
	{
		buffer[i] = left[i];
		//buffer.get_str()[i] = left.get_str()[i]; 
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		buffer[i + left.get_size() - 1] = right[i];
		//buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i]; 
	}
	return buffer;
}
