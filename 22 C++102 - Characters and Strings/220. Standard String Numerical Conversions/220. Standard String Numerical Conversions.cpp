// 220. Standard String Numerical Conversions

#include <iostream>
#include <string>

int main()
{
#if 0

	int i{ 16 };
	float f{ 16.5f };

	std::string s1{ "Hello, Android " };

	std::cout << s1 + std::to_string(f) << std::endl;
#endif

#if 1
	std::string str{ "3.14159" };
	//std::string str{ "-3.14159" };
	//std::string str{ "Bob" }; //crush

	//convert to numerical values
	int i = std::stoi(str);
	unsigned long ul = std::stoul(str);
	double d = std::stod(str);

	std::cout << i << std::endl;
	std::cout << ul << std::endl;
	std::cout << d << std::endl;

#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}