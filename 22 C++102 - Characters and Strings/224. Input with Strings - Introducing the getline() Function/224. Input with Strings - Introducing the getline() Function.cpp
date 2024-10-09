// 224. Input with Strings - Introducing the getline() Function

#include <iostream>
#include <string>

int main()
{
#if 0
	char name[20]{};

	std::cout << "Enter your first name: ";

	std::cin >> name; // not save character after space

	std::cout << "Your first name is: " << name << std::endl;
#endif

#if 0
	std::string name{};

	std::cout << "Enter your first name: ";

	std::cin >> name;

	std::cout << "Your first name is: " << name << std::endl;
#endif

#if 0
	char fullName[20]{};

	std::cout << "Enter your full name: ";

	//std::cin.getline(fullName, 20); // input and save 20 characters whith space
	std::cin.getline(fullName, 20, 'A'); // not save after A symbol

	std::cout << "Your full name is: " << fullName << std::endl;
#endif

#if 0
	std::string fullName{};

	std::cout << "Enter your full name: ";

	//std::cin >> fullName;

	//std::getline(std::cin, fullName);
	std::getline(std::cin, fullName, 'm');

	std::cout << "Your full name is: " << fullName << std::endl;
#endif

#if 1
	std::string toDoList;

	std::getline(std::cin, toDoList, '_');

	std::cout << toDoList << std::endl;
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}