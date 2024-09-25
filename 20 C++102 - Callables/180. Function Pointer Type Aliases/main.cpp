// 180. Function Pointer Type Aliases

#include <iostream>

//example1
int add(int p, int q) { return p + q; }

int multiply(int p, int q) { return p * q; }

typedef int(*mathOperation)(int, int);

using mathOperator1 = int(*)(int, int);


//example2
template<typename T>
bool lessThan(const T& operand1, const T& operand2)
{
	if (operand1 < operand2)
		return true;
	else
		return false;
}

template<typename T>
bool greaterThan(const T& operand1, const T& operand2)
{
	if (operand1 > operand2)
		return true;
	else
		return false;
}

template<typename T>
using Test = bool(*)(const T&, const T&);

// a typedef template is illegal!
//template<typename T>
//typedef bool(*nope)(const T&, const T&);

template<typename T>
void compare(T operand1, T operand2, Test<T> comarator)
{
	if (comarator(operand1, operand2))
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
}


//example3
template<typename T>
T getElement(const T scoresP[], int sizeP, Test<T> comparator)
{
	T element = scoresP[0];

	for (int i = 0; i < sizeP; i++)
	{
		if (comparator(scoresP[i], element))
		{
			element = scoresP[i];
		}
	}
	return element;
}


int main()
{
#if 0
	//int(*fPtr)(int, int) = multiply;
	//mathOperation op = multiply;
	mathOperator1 op = add;

	if (op)
	{
		std::cout << op(5, 5) << std::endl;
	}
	else
	{
		std::cout << "nullptr" << std::endl;
	}
#endif

#if 0
	int x{ 5 }, y{ 25 };

	std::cout << x << " > " << y << std::endl;
	compare(x, y, greaterThan);

	std::cout << x << " < " << y << std::endl;
	compare(x, y, lessThan);

#endif

#if 1
	const int ARRAY_SIZE = 4;
	int victoryPoints[ARRAY_SIZE]{ 1, 3, 5, 4 };

	std::cout << getElement(victoryPoints, ARRAY_SIZE, lessThan) << std::endl;

#endif

	std::cout << "END\n";
	return 0;
}