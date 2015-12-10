/****************************************************************************

ModuleName:
Source.cpp

Abstract:
This code demonstrates calculating with reverse polish notation method.

Author:
Cherednikov Michael

Date:
2015-12-03

****************************************************************************/
#include <cassert> // для assert
#include <iostream>
#include <iomanip> // для setw
#include <iostream>
#include <io.h>
#include <string>
#include <cmath>

using namespace std;

template <typename T>
class Stack
{
private:
	T *stackPtr;                      // указатель на стек
	const int size;                   // максимальное количество элементов в стеке
	int top;                          // номер текущего элемента стека
public:
	Stack(int = 10);                  // по умолчанию размер стека равен 10 элементам
	Stack(const Stack<T> &);          // конструктор копирования
	~Stack();                         // деструктор

	inline void push(const T &);     // поместить элемент в вершину стека
	inline T pop();                   // удалить элемент из вершины стека и вернуть его
	inline void printStack();         // вывод стека на экран
	inline const T &Peek(int) const; // n-й элемент от вершины стека
	inline int getStackSize() const;  // получить размер стека
	inline T *getPtr() const;         // получить указатель на стек
	inline int getTop() const;        // получить номер текущего элемента в стеке
};

// реализация методов шаблона класса STack

// конструктор Стека
template <typename T>
Stack<T>::Stack(int maxSize) :
	size(maxSize) // инициализация константы
{
	stackPtr = new T[size]; // выделить память под стек
	top = 0; // инициализируем текущий элемент нулем;
}

// конструктор копирования
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) :
	size(otherStack.getStackSize()) // инициализация константы
{
	stackPtr = new T[size]; // выделить память под новый стек
	top = otherStack.getTop();

	for (int ix = 0; ix < top; ix++)
		stackPtr[ix] = otherStack.getPtr()[ix];
}

// функция деструктора Стека
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr; // удаляем стек
}

// функция добавления элемента в стек
template <typename T>
inline void Stack<T>::push(const T &value)
{
	// проверяем размер стека
	assert(top < size); // номер текущего элемента должен быть меньше размера стека

	stackPtr[top++] = value; // помещаем элемент в стек
}

// функция удаления элемента из стека
template <typename T>
inline T Stack<T>::pop()
{
	// проверяем размер стека
	assert(top > 0); // номер текущего элемента должен быть больше 0

	stackPtr[--top]; // удаляем элемент из стека
	return 0;
}

// функция возвращает n-й элемент от вершины стека
template <class T>
inline const T &Stack<T>::Peek(int nom) const
{
	//
	assert(nom <= top);

	return stackPtr[top - nom]; // вернуть n-й элемент стека
}

// вывод стека на экран
template <typename T>
inline void Stack<T>::printStack()
{
	for (int ix = top - 1; ix >= 0; ix--)
		cout << "|" << setw(4) << stackPtr[ix] << endl;
}

// вернуть размер стека
template <typename T>
inline int Stack<T>::getStackSize() const
{
	return size;
}

// вернуть указатель на стек (для конструктора копирования)
template <typename T>
inline T *Stack<T>::getPtr() const
{
	return stackPtr;
}

// вернуть размер стека
template <typename T>
inline int Stack<T>::getTop() const
{
	return top;
}

int table(char first, char second) // 1st - на стрелке(горизонталь)
								   // 2nd - прошлый который ушел в Москву(вертикаль)
{
	char massivGOR[11];
	char massivVERT[10];

	int massiv[10][11];
	int bufGOR, bufVERT;
	////////////////////////////////////////////////////////заполнение массива
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			massiv[i][j] = 2;
		}
	}
	for (int j = 1; j < 10; j++)
	{
		massiv[0][j] = 1;
	}
	for (int j = 3; j < 10; j++)
	{
		massiv[1][j] = 1;
	}
	for (int j = 3; j < 10; j++)
	{
		massiv[2][j] = 1;
	}
	for (int j = 5; j < 10; j++)
	{
		massiv[3][j] = 1;
	}
	for (int j = 5; j < 10; j++)
	{
		massiv[4][j] = 1;
	}
	for (int j = 6; j < 10; j++)
	{
		massiv[5][j] = 1;
	}
	for (int j = 7; j < 10; j++)
	{
		massiv[6][j] = 1;
	}
	for (int j = 8; j < 10; j++)
	{
		massiv[7][j] = 1;
	}
	massiv[8][9] = 1;

	for (int j = 1; j < 10; j++)
	{
		massiv[9][j] = 1;
	}



	massiv[0][0] = 4;
	massiv[9][0] = massiv[0][10] = 5;
	massiv[9][10] = 3;
	massiv[9][9] = 1;

	//////////////////////////////////////////////////////////
	massivGOR[0] = massivVERT[0] = '|';
	massivGOR[1] = massivVERT[1] = '+';
	massivGOR[2] = massivVERT[2] = '-';
	massivGOR[3] = massivVERT[3] = '*';
	massivGOR[4] = massivVERT[4] = '/';
	massivGOR[5] = massivVERT[5] = '^';
	massivGOR[6] = massivVERT[6] = 's';
	massivGOR[7] = massivVERT[7] = 'c';
	massivGOR[8] = massivVERT[8] = 'I';
	massivGOR[9] = massivVERT[9] = '(';
	massivGOR[10] = ')';

	//определение ситуации
	for (int j = 0; j < 11; j++)
	{
		if (first == massivGOR[j]) bufGOR = j;
	}
	//определение ситуации
	for (int i = 0; i < 10; i++)
	{
		if (second == massivVERT[i]) bufVERT = i;
	}
	return massiv[bufVERT][bufGOR];
}

string convert(string str)
{
	string converted;
	Stack<char> stackSymbol(30);
	int i = 0;
	stackSymbol.push('|');
	char last = stackSymbol.Peek(1);
	while (i < str.length())
	{
		if (isdigit(str.at(i)) != 0)
		{	
			if ((i != 0)&&(str.at(i - 1) == '-'))
			{
				converted += '0';
				converted += ' ';
				while ((i < str.length()) && ((isdigit(str.at(i)) != 0) || (str.at(i) == '.')))
				{
					converted += str.at(i);
					i++;
				}
			}
			else
			{
				while ((i < str.length()) && ((isdigit(str.at(i)) != 0) || (str.at(i) == '.')))
				{
					converted += str.at(i);
					i++;
				}
			}
			i--;
			converted += ' ';
		}
		else
		{
			switch (table(str.at(i), last))
			{
			case 1:
			{
				stackSymbol.push(str.at(i));
				last = stackSymbol.Peek(1);
				break;
			}
			case 2:
			{											//////////////////////////////////БУДЕТ ВАЙЛ 
				while (table(str.at(i), last) == 2)
				{
					converted += stackSymbol.Peek(1);
					converted += ' ';
					stackSymbol.pop();
					last = stackSymbol.Peek(1);
				}

				if (table(str.at(i), stackSymbol.Peek(1)) == 3)
				{
					stackSymbol.pop();
					last = stackSymbol.Peek(1);
				}

				if (table(str.at(i), stackSymbol.Peek(1)) == 1)
				{
					stackSymbol.push(str.at(i));
					last = stackSymbol.Peek(1);
				}
				
				break;
			}
			case 3:
			{
				stackSymbol.pop();
				last = stackSymbol.Peek(1);
				break;
			}
			case 4:
				return converted;
			case 5:
				throw "ERROR in formula";
			default:
				throw "ERROR in table";
			}
		}
		i++;
	}
	while (stackSymbol.getTop() != 0)
	{
		converted += stackSymbol.Peek(1);
		stackSymbol.pop();
		converted += ' ';
	}
	return converted;
};

double converttod(string input)
{
	double full = 0;
	double fact = 0;
	double conv = 0;
	string subfull;
	string subfact;
	int i = 0;
	bool FLAGdrobn = false;

	while (i < input.length())
	{
		if (input.at(i) == '.') FLAGdrobn = true;
		i++;
	}
	i = 0;
	if (FLAGdrobn)
	{
		while (input.at(i) != '.')
		{
			subfull += input.at(i);
			i++;
		}
		full = stod(subfull);
		i++;

		while (i < input.length())
		{
			subfact += input.at(i);
			i++;
		}
		fact = stod(subfact);
		fact = fact / (pow(10,subfact.length()));

		conv = full + fact;
	} 
	else
	{
		while (i < input.length())
		{
			subfull += input.at(i);
			i++;
		}
		conv = stod(subfull);
	}
	return conv;
}

double count(string converted)
{
	double result = 0,a = 0,b = 0;
	Stack<double> stackNumber(30);
	string substring;

	for (int i = 0; i < converted.length(); i++)
	{
		if (isdigit(converted.at(i)) != 0) 
		{
			while ((i<converted.length()) && ((isdigit(converted.at(i)) != 0) || (converted.at(i) == '.')))
			{ 
				substring += converted.at(i);
				i++;
			}
			i--;
			stackNumber.push(converttod(substring));
			substring = "";
		}

		else if ((converted.at(i) != ' ') && (converted.at(i) != '|'))
		{
			/*a = stackNumber.Peek(1);
			stackNumber.pop();
			if (stackNumber.getTop() >= 1) 
			{
				b = stackNumber.Peek(1);
				stackNumber.pop();
			}*/
			switch (converted.at(i))
			{
				case '+': 
				{
					a = stackNumber.Peek(1);
					stackNumber.pop();
					b = stackNumber.Peek(1);
					stackNumber.pop();
					result = b + a;
					break;
				}
				case '-': 
				{ 
					a = stackNumber.Peek(1);
					stackNumber.pop();
					b = stackNumber.Peek(1);
					stackNumber.pop();
					result = b - a; 
					break;
				}
			case '*': 
				{
					a = stackNumber.Peek(1);
					stackNumber.pop();
					b = stackNumber.Peek(1);
					stackNumber.pop();
					result = b*a; 
					break;
				}
			case '/': 
				{
					a = stackNumber.Peek(1);
					stackNumber.pop();
					b = stackNumber.Peek(1);
					stackNumber.pop();
					result = b / a;
					break;
				}
			case '^':
				{
					a = stackNumber.Peek(1);
					stackNumber.pop();
					b = stackNumber.Peek(1);
					stackNumber.pop();
					result = pow(b, a);
					break;
				}
			case 's':
				{
					a = stackNumber.Peek(1);
					stackNumber.pop();
					result = sin(a);
					break;
				}
			case 'c':
			{
				a = stackNumber.Peek(1);
				stackNumber.pop();
				result = cos(a);
				break;
			}
			}
			stackNumber.push(result);
		}
	}
	return stackNumber.Peek(1);
}

void main()
{
	setlocale(LC_ALL, "");
	string str, converted;
	cout << "Enter string : ";
	cin >> str;
	cout << endl << endl << "Infix notation : " << str << endl << endl;

	converted = convert(str);
	cout << endl << "Reverse polish notation : " << converted << endl << endl << endl << endl;

	cout << endl << "Result : " << count(converted) << endl << endl << endl << endl;
}