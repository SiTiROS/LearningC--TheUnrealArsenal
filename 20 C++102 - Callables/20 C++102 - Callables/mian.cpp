#include <iostream>

//177. Function Pointers
void hello() { std::cout << "hello human!" << std::endl; }

int square(int p) { return p * p; }

int add(int x, int y) { return x + y; }

int multiply(int x, int y) { return x * y; }

int main()
{
	//177. Function Pointers

	//int(*fPtr)(int) = nullptr;
	//int x = square;

	//std::cout << square << std::endl;
	//std::cout << &square << std::endl;

	int(*fPtr)(int) = nullptr;
	fPtr = square; // or fPtr = &square; не обязательно &
	if (fPtr)
	{
		std::cout << "not nullptr" << std::endl;
		std::cout << fPtr << std::endl;
		std::cout << fPtr(5) << std::endl;
		std::cout << (*fPtr)(5) << std::endl; // не обязательно *
	}
	else
	{
		std::cout << "nullptr" << std::endl;
		std::cout << fPtr << std::endl;
	}

	int(*fPtr1)(int, int) = add;
	fPtr1 = multiply;
	if (fPtr1)
	{
		std::cout << fPtr1(5, 5) << std::endl;
	}

	auto fPtr2 = multiply;
	if (fPtr2)
	{
		std::cout << fPtr2(5, 5) << std::endl;
	}

	int(*fPtr3)(int, int) { multiply }; // списковая инициализация




	std::cout << "END\n";
	return 0;
}