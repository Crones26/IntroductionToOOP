#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n--------------------------------------------\n"

//////////////////////////////////////////////////////////
//			ОБЪЯВЛЕНИЕ КЛССа(Class Decklaration)		//
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
//#define CONSTRUCTORS_CHECK
//#define OPERATOR_PLUS_CHECK
//#define MOVE_ASSIGNMENT_CHECK
#define CALLING_CONSTRUCTIORS

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK

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

#endif // CONSTRUCTORS_CHECK

#ifdef OPERATOR_PLUS_CHECK

	String str1 = "Hello";
	String str2 = "World";

	cout << delimiter << endl;
	String str3 = str1 + str2;
	cout << str3 << endl;
	cout << delimiter << endl;

	cout << str1 << endl;
	cout << str2 << endl;

#endif // OPERATOR_PLUS_CHECK

#ifdef MOVE_ASSIGNMENT_CHECK
	String str1 = "Hello";
    String str2 = "World";

	cout << delimiter << endl;
	//String temp = str1 + str2;	//Move constructor
	String temp;
	temp = str1 + str2; // Move assignment
	temp.print();
	cout << delimiter << endl;
	//String str3;				// Создаем пустой объект str3
	//str3 = std::move(temp);	// Перемещаем temp в str3
	//cout << str3 << endl;
	//cout << delimiter << endl;

#endif // MOVE_ASSIGNMENT_CHECK

#ifdef CALLING_CONSTRUCTIORS

	String str1;	//Default constructor
	str1.print();

	//Single-Argument constructor 'int'
	//String str2 = 8;	//explicit constructor так вызвать невозможно
	String str2(8);		//explicit constructor можно вызвать только так
	str2.print();

	String str3 = "Hello";	//Single-Argument constructor 'char'
	str3.print();

	String str4();	//Здесь НЕ вызывается никакой конструктор, и не создается объект,
					//здесь объявляется функция str4(), которая не принимает никаких параметров,
					//и возвращает значение типа 'String'.
					//Т.е., таким образом DefaultConstructor вызвать невозможно,
	//str4.print();
	//Если нужно явно вызвать DefaultConstructor, это делается следующим образом:
	String str5{};	//Явный вызов конструктора по умолчанию
	str5.print();

	//String str6 = str3;	//CopyConstructor
	//String str6(str3);	//CopyConstructor
	String str6{ str3 };	//CopyConstructor
	str6.print();
	//Следовательно, абсолютно любой конструктор можно вызвать при помощи () или {}

#endif // CALLING_CONSTRUCTIORS

}