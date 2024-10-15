// 234. Internal Justification of the Field Width

#include <iostream>
#include <iomanip>

int main()
{
#if 0
	double d{ 3.14159 };

	std::cout << std::showpos;
	std::cout << std::right;
	std::cout << std::setw(12) << d << std::endl;

	std::cout << std::left;
	std::cout << std::setw(12) << d << std::endl;

	std::cout << std::internal;
	std::cout << std::setw(12) << d << std::endl;
#endif

#if 1
	int x{ 255 };

	std::cout << std::showpos;
	std::cout << "The integer is: " << x << std::endl;

	std::cout << std::showbase;

	std::cout << "\nOutput in different bases..." << std::endl;
	std::cout << "The integer in octal is: " << std::oct << x << std::endl;
	std::cout << "The integer in decimal is: " << std::dec << x << std::endl;


	std::cout << std::internal;
	std::cout << std::uppercase;
	std::cout << "The integer in hexadecimal is: ";
	std::cout << std::hex << std::setw(10) << x << std::endl;
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}