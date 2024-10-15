// 230. Show the Positive Sign and Show the Decimal Point

#include <iostream>

int main()
{
#if 0
	int x{ -5 }, y{ 7 };

	std::showpos(std::cout);
	std::cout << x << '\t' << y << std::endl;

	std::noshowpos(std::cout);
	std::cout << x << '\t' << y << std::endl;
#endif

#if 1
	double d1{ 3.1415926535 };
	double d2{ 3.141 };
	double d3{ 3.0 };

	std::cout << std::showpoint;
	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << d3 << std::endl;
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}