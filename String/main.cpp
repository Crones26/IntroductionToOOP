#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n--------------------------------------------\n"

class String
{
	int	size;  //Размер строки в байтах
	char* str; //Указатель на строку в динамической памяти
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	//			Constructors:
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)
		{
			this->str[i] = str[i];
		}
		cout << "Constructor:\t\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyConstructor:\t" << this << endl;
	}
	//				Operators:
	String& operator=(const String& other)
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
	//				Indexing operators
	char& operator[](int index)
	{
		return str[index];
	}
	const char& operator[](int index) const
	{
		return str[index];
	}
	//				Methods:
	void print()const
	{
		cout << "Obj;\t\t\t" << this << endl;
		cout << "Size:\t\t\t" << size << endl;
		cout << "Addr:\t\t\t" << &str << endl;
		cout << "Str:\t\t\t" << str << endl;
		cout << delimiter << endl;
	}
	
};

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+(const String& left, const String& right)
{
	String buffer(left.get_size() + right.get_size() - 1);
	buffer.print();
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

void main()
{
	setlocale(LC_ALL, "");

	String str1;
	str1.print();

	String str2(8);
	str2.print();

	String str3 = "Hello";
	//cout << str3 << endl;
	str3.print();

	str3 = str3;

	String str4 = "World";
	//cout << str4 << endl;
	str4.print();

	//String str5 = str3 + " " + str4;
	String str5;
	str5 = str3 + " " + str4;
	
	cout << delimiter << endl;
	cout << str5 << endl;
	cout << delimiter << endl;

}