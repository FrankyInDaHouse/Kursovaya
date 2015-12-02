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
	char massivGOR[7];
	char massivVERT[6];

	massivGOR[0] = massivVERT[0] = '|';
	massivGOR[1] = massivVERT[1] = '+';
	massivGOR[2] = massivVERT[2] = '-';
	massivGOR[3] = massivVERT[3] = '*';
	massivGOR[4] = massivVERT[4] = '/';
	massivGOR[5] = massivVERT[5] = '(';
	massivGOR[6] = ')';


	int massiv[6][7];
	int bufGOR, bufVERT;
	////////////////////////////////////////////////////////���������� �������
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 7; j++)
		{
			massiv[i][j] = 2;
		}
	massiv[0][0] = 4;
	for (int j = 1; j < 6; j++)
	{
		massiv[0][j] = 1;
	}
	massiv[0][6] = 5;
	for (int j = 3; j < 6; j++)
	{
		massiv[1][j] = 1;
	}
	for (int j = 3; j < 6; j++)
	{
		massiv[2][j] = 1;
	}
	massiv[3][5] = 1;
	massiv[4][5] = 1;

	for (int j = 0; j < 7; j++)
	{
		massiv[5][j] = 1;
	}
	massiv[5][0] = 5;
	massiv[5][6] = 3;
	//////////////////////////////////////////////////////////


	//����������� ��������
	for (int j = 0; j < 7; j++)
	{
		if (first == massivGOR[j]) bufGOR = j;
	}
	//����������� ��������
	for (int i = 0; i < 6; i++)
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
			converted += str.at(i);
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
				
				break;
			}
			case 3:
			{
				stackSymbol.pop();
				break;
			}
			case 4:
				return converted;
			case 5:
				return "error in formula";
			default:
				return "error in table";
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

double count(string converted)
{
	double result = 0;
	Stack<double> stackSymbol(30);
	for (int i = 0; i < converted.length(); i++)
	{









	}
	return stackSymbol.Peek(1);
}

void main()
{
	setlocale(LC_ALL, "");
	string str, converted;
	cout << "������� ������ ��� ���������� : ";
	cin >> str;
	cout << endl << endl << "������ � ��������� ������� : " << str << endl << endl;

	converted = convert(str);
	cout << endl << "������ � ����������� ������� : " << converted << endl << endl << endl << endl;

	//cout << endl << "��������� ���������� : " << count(converted) << endl << endl << endl << endl;
}