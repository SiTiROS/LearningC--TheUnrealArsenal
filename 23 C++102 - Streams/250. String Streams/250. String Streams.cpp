// 250. String Streams

#include <iostream>
#include <sstream> //for string streams
#include <string>

int main()
{
#if 0
	std::string playerStats{ "Bob 47" };
	std::istringstream iss{ playerStats };

	std::string playerName{};
	int playerLevel{};

	iss >> playerName >> playerLevel;

	std::cout << playerName << " is Level: " << playerLevel << std::endl;
#endif

#if 0
	std::string playerStats{ "Bob 47" };
	std::stringstream ss{ playerStats };

	std::string playerName{};
	int playerLevel{};

	ss >> playerName >> playerLevel;

	std::cout << playerName << " is Level: " << playerLevel << std::endl;
#endif

#if 0
	std::string playerStats{ };
	std::cout << "Enter player name followed by player level: ";

	std::string playerName{};
	int playerLevel{};

	std::cin >> playerName;

	std::cout << "The Player: " << playerName;

	std::cin >> playerLevel;

	std::cout << "\nThe Player Level: " << playerLevel << std::endl;
#endif

#if 0
	std::string playerStats{ "Bob 47" };
	std::istringstream iss{ playerStats };

	std::string playerName{};
	int playerLevel{};

	iss >> playerName >> playerLevel;

	std::cout << playerName << " is Level: " << playerLevel << std::endl;
	std::cout << playerStats << std::endl;
#endif

#if 0
	std::ostringstream oss{};

	oss << "Player Bob is Level: " << 47;

	oss.str("Player Bob is Level 66");

	std::cout << oss.str();
#endif

#if 1
	std::string userInput{};
	int num{};
	bool isInputValid{ false };

	do
	{
		std::cout << "Please enter an integer: ";
		std::cin >> userInput;

		std::istringstream iss{ userInput };

		if (iss >> num)
		{
			std::cout << "The integer is: " << num << std::endl;
			isInputValid = true;
		}
		else
		{
			std::cout << "Incorrect input. Please try again." << std::endl;

		}
		//std::string discard;
		//std::getline(std::cin, discard);

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (!isInputValid);
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}