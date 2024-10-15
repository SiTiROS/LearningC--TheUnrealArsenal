// 231. Setting the Precision for Floating-Point Values

#include <iostream>
#include <iomanip>

int main()
{
#if 1
	double d1{ 3.1415926535 };
	double d2{ 123456 };
	double d3{ 123456789 };
	double d4{ 0.0000314159 };
	double d5{ 1.3e5 };
	double d6{ 0.00001 };
	float f6{ 0.00001f };

	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << d3 << std::endl;
	std::cout << d4 << std::endl;
	std::cout << d5 << std::endl;
	std::cout << d6 << std::endl;
	std::cout << f6 << std::endl;
	std::cout << std::endl;

	//std::cout.precision(6);
	std::cout << std::setprecision(10);
	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << d3 << std::endl;
	std::cout << d4 << std::endl;
	std::cout << d5 << std::endl;
	std::cout << d6 << std::endl;
	std::cout << f6 << std::endl;

	std::cout << std::fixed << std::setprecision(6) << d6 << std::endl;
	std::cout << std::fixed << std::setprecision(6) << f6 << std::endl;
#endif





#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}