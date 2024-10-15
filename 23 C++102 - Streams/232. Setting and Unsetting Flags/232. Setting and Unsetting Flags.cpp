// 232. Setting and Unsetting Flags

#include <iostream>
#include <iomanip>

int main()
{
#if 0
	double d1{ 3.1415926535 };
	double d2{ 123456 };
	double d3{ 123456789 };
	double d4{ 0.0000314159 };

	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << d3 << std::endl;
	std::cout << d4 << std::endl;
	std::cout << std::endl;

	//std::cout.setf(std::ios::fixed);
	//std::cout << std::fixed;
	std::cout << std::scientific;
	std::cout << std::showpos;
	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << d3 << std::endl;
	std::cout << d4 << std::endl;
	std::cout << std::endl;

	std::cout.unsetf(std::ios::scientific | std::ios::showpos);
	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << d3 << std::endl;
	std::cout << d4 << std::endl;
#endif

#if 0
	double d1{ 3.1415926535 };
	double d2{ 123456 };
	double d3{ 123456789 };
	double d4{ 0.0000314159 };

	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << d3 << std::endl;
	std::cout << d4 << std::endl;
	std::cout << std::endl;

	//std::cout.setf(std::ios::scientific | std::ios::showpos);
	std::cout.flags(std::ios::scientific | std::ios::showpos);
	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << d3 << std::endl;
	std::cout << d4 << std::endl;
	std::cout << std::endl;

	std::cout.unsetf(std::ios::scientific | std::ios::showpos);
	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << d3 << std::endl;
	std::cout << d4 << std::endl;
#endif

#if 1
	double d1{ 3.1415926535 };
	double d2{ 123456 };
	double d3{ 123456789 };
	double d4{ 0.0000314159 };

	std::cout << std::fixed;
	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << d3 << std::endl;
	std::cout << d4 << std::endl;
	std::cout << std::endl;

	std::cout << std::resetiosflags(std::ios::fixed);
	std::cout << std::setiosflags(std::ios::scientific | std::ios::showpos);
	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << d3 << std::endl;
	std::cout << d4 << std::endl;
	std::cout << std::endl;

	std::cout << std::resetiosflags(std::ios::scientific | std::ios::showpos);
	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << d3 << std::endl;
	std::cout << d4 << std::endl;
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}