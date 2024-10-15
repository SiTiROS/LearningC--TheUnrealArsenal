// 240. Reading from a File

#include <iostream>
#include <fstream>
#include <string>

void openFile()
{
	std::ifstream in_file;

	in_file.open("Text.txt");

	if (in_file.fail())
	{
		std::cerr << "File could not be opened!" << std::endl;
		//exit(1); //Terminate the program
		exit(EXIT_FAILURE); //Terminate the program
	}
	else
	{
		std::cout << "File opened secessfully!" << std::endl;
	}

	in_file.close();
}

int main()
{
#if 0
	openFile();
#endif

#if 0
	int score{};
	std::string playerName{};

	std::cout << "Enter the Player Name, followed by the Score: ";
	std::cin >> playerName >> score;

	std::cout << "\nThe Player Name and Score is: " << playerName;
	std::cout << "\t" << score << std::endl;
#endif

#if 1
	std::ifstream in_file;

	in_file.open("Text.txt");

	if (!in_file.is_open())
	{
		std::cerr << "File could not be opened!" << std::endl;
		exit(EXIT_FAILURE); //Terminate the program
	}
	else
	{
		int playerScore{};
		std::string playerName{};

		//read from file
		in_file >> playerName >> playerScore;

		std::cout << "Player Name: " << playerName << std::endl;
		std::cout << "Player Score: " << playerScore << std::endl;
	}

	in_file.close();
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	exit(EXIT_SUCCESS);
}