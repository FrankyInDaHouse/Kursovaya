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

int table(char first,char second) // 1st - на стрелке(горизонталь)
								  // 2nd - прошлый который ушел в Москву(вертикаль)
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
	////////////////////////////////////////////////////////заполнение массива
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
	
	
	//определение ситуации
	for (int j = 0; j < 7; j++)
	{
		if (first == massivGOR[j]) bufGOR = j;
	}
	//определение ситуации
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
	int i = 0 , flag = 0;
	char last = str.at(0);
	while (i < str.length()) 
	{
		if (isdigit(str.at(i)) != 0) converted += str.at(i);			// если у нас цифра , то сразу записываем её в Киев
		else		
		{		
			if (table(str.at(i), last) == 1)
			{
				stackSymbol.push(str.at(i));
				last = stackSymbol.Peek(1);
				flag = 1;
			}
			if (table(str.at(i), last) == 2 && (flag != 1))
				{
					converted += stackSymbol.Peek(1);
					stackSymbol.pop();
					last = stackSymbol.Peek(1);
				}
			if (table(str.at(i), last) == 3) 
				{
					stackSymbol.pop();
					if (stackSymbol.getTop() > 0)
						last = stackSymbol.Peek(1);
				}
			if (table(str.at(i), last) == 4) break; 
			if (table(str.at(i), last) == 5) exit; // error
		}
		flag = 0;
		i++;
	}
	while(stackSymbol.getTop()>0)
	{
		converted += stackSymbol.Peek(1);
		stackSymbol.pop();
	}
	return converted;
};


void main()
{
	setlocale(LC_ALL, "");
	string str;
	double result = 0;
	cout << "Введите строку для вычисления : ";
	cin >> str;
	cout << endl << endl << "Строка в инфиксной нотации : " << str << endl << endl;

	cout << endl << "Строка в постфиксной нотации : " << convert(str) << endl << endl << endl << endl;
}