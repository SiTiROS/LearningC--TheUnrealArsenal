// 179. Arrays of Function Pointers

#include <iostream>

int add(int p, int q) { return p + q; }

int multiply(int p, int q) { return p * q; }

int main()
{
	// an array of function pointers
	int(*funcPtrArr[])(int, int) = { add, multiply }; // массив указателей на функции
	//int array[] = {0 , 1};

	int x{}, y{}, choice{};

	std::cout << "Enter two numbers: ";
	std::cin >> x >> y;

	std::cout << "Enter 0 to add, 1 to multiply: ";
	std::cin >> choice;

	std::cout << (*funcPtrArr[choice])(x, y) << std::endl;

	std::cout << "END\n";
	return 0;
}