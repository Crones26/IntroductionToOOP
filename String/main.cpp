#include "String.h"

//#define CONSTRUCTORS_CHECK
#define OPERATOR_PLUS_CHECK
//#define MOVE_ASSIGNMENT_CHECK
//#define CALLING_CONSTRUCTIORS

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