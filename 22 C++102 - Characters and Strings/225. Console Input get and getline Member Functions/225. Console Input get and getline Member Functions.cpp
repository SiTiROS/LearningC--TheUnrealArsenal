// 225. Console Input get and getline Member Functions

#include <iostream>
#include <string>

int main()
{
#if 0
	int age{};

	std::cout << "Enter your age: ";
	std::cin >> age;

	std::cout << "Your age is: " << age << std::endl;

	std::cin.get();
	std::cin.get();
#endif

#if 0
	int age{};
	std::string fullName{};

	std::cout << "Enter your age: ";
	std::cin >> age;

	std::cin.get();

	std::cout << "Enter your full name: ";
	std::getline(std::cin, fullName, '\n');

	std::cout << fullName << ", age " << age << ", reporting for duty!" << std::endl;
#endif

#if 1
	char firstName[10]{};
	char lastName[10]{};

	std::cout << "Enter your first name: ";
	std::cin.getline(firstName, 10);

	std::cout << "Enter your last name: ";
	std::cin.get(lastName, 10);

	std::cout << "Welcome: " <<firstName << ' ' << lastName << std::endl;
#endif



#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}