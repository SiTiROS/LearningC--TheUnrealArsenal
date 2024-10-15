// 233. Stream Manipulators with Integers

#include <iostream>
//#include <bitset>

int main()
{
#if 1
	int x{ 255 };

	std::cout << std::showpos;
	std::cout << "The integer is: " << x << std::endl;

	std::cout << std::showbase;
	std::cout << std::uppercase;
	std::cout << "Output in different bases..." << std::endl;
	//std::cout << std::noshowbase;
	//std::cout << std::noshowpos;
	//std::cout << std::nouppercase;
	std::cout << "The integer in octal is: " << std::oct << x << std::endl;
	std::cout << "The integer in decimal is: " << std::dec << x << std::endl;
	std::cout << "The integer in hexadecimal is: " << std::hex << x << std::endl;
	//std::cout << "The integer in binary is: " << std::bitset<32>(x) << std::endl;
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}