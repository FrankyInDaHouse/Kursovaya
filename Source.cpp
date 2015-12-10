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
#include <cassert> // ��� assert
#include <iostream>
#include <iomanip> // ��� setw
#include <iostream>
#include <io.h>
#include <string>
#include <cmath>

using namespace std;

template <typename T>
class Stack
{
private:
	T *stackPtr;                      // ��������� �� ����
	const int size;                   // ������������ ���������� ��������� � �����
	int top;                          // ����� �������� �������� �����
public:
	Stack(int = 10);                  // �� ��������� ������ ����� ����� 10 ���������
	Stack(const Stack<T> &);          // ����������� �����������
	~Stack();                         // ����������

	inline void push(const T &);     // ��������� ������� � ������� �����
	inline T pop();                   // ������� ������� �� ������� ����� � ������� ���
	inline void printStack();         // ����� ����� �� �����
	inline const T &Peek(int) const; // n-� ������� �� ������� �����
	inline int getStackSize() const;  // �������� ������ �����
	inline T *getPtr() const;         // �������� ��������� �� ����
	inline int getTop() const;        // �������� ����� �������� �������� � �����
};

// ���������� ������� ������� ������ STack

// ����������� �����
template <typename T>
Stack<T>::Stack(int maxSize) :
	size(maxSize) // ������������� ���������
{
	stackPtr = new T[size]; // �������� ������ ��� ����
	top = 0; // �������������� ������� ������� �����;
}

// ����������� �����������
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) :
	size(otherStack.getStackSize()) // ������������� ���������
{
	stackPtr = new T[size]; // �������� ������ ��� ����� ����
	top = otherStack.getTop();

	for (int ix = 0; ix < top; ix++)
		stackPtr[ix] = otherStack.getPtr()[ix];
}

// ������� ����������� �����
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr; // ������� ����
}

// ������� ���������� �������� � ����
template <typename T>
inline void Stack<T>::push(const T &value)
{
	// ��������� ������ �����
	assert(top < size); // ����� �������� �������� ������ ���� ������ ������� �����

	stackPtr[top++] = value; // �������� ������� � ����
}

// ������� �������� �������� �� �����
template <typename T>
inline T Stack<T>::pop()
{
	// ��������� ������ �����
	assert(top > 0); // ����� �������� �������� ������ ���� ������ 0

	stackPtr[--top]; // ������� ������� �� �����
	return 0;
}

// ������� ���������� n-� ������� �� ������� �����
template <class T>
inline const T &Stack<T>::Peek(int nom) const
{
	//
	assert(nom <= top);

	return stackPtr[top - nom]; // ������� n-� ������� �����
}

// ����� ����� �� �����
template <typename T>
inline void Stack<T>::printStack()
{
	for (int ix = top - 1; ix >= 0; ix--)
		cout << "|" << setw(4) << stackPtr[ix] << endl;
}

// ������� ������ �����
template <typename T>
inline int Stack<T>::getStackSize() const
{
	return size;
}

// ������� ��������� �� ���� (��� ������������ �����������)
template <typename T>
inline T *Stack<T>::getPtr() const
{
	return stackPtr;
}

// ������� ������ �����
template <typename T>
inline int Stack<T>::getTop() const
{
	return top;
}

int table(char first, char second) // 1st - �� �������(�����������)
								   // 2nd - ������� ������� ���� � ������(���������)
{
	char massivGOR[11];
	char massivVERT[10];

	int massiv[10][11];
	int bufGOR, bufVERT;
	////////////////////////////////////////////////////////���������� �������
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

	//����������� ��������
	for (int j = 0; j < 11; j++)
	{
		if (first == massivGOR[j]) bufGOR = j;
	}
	//����������� ��������
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
			{											//////////////////////////////////����� ���� 
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