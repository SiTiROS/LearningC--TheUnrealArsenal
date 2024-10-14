// 228. The Global Stream Objects

#include <iostream>


int main()
{
#if 0

	int age{};

	std::cout << "Enter your age: " << std::endl;

	std::cin >> age;

	if (age < 0)
	{
		std::cerr << "Age cannot be a negative value!\n";
		std::clog << "Terminate the program. The user entered an incorrect value.\n";
		return 0;
	}

	std::cout << "Your age is: " << age << std::endl;
#endif

#if 1
	bool myBool{ true };

	std::cout << "Enter boolean value: " << std::endl;
	std::cin >> std::boolalpha;
	std::cin >> myBool;

	std::cout << std::boolalpha;
	std::cout << myBool << std::endl;
	
	std::cout << std::noboolalpha;
	std::cout << myBool << std::endl;
#endif


#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}