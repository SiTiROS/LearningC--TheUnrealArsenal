// 241. Continuously Reading from a File

#include <iostream>
#include <fstream>
#include <string>

int main()
{
#if 0
	std::ifstream in_file;

	in_file.open("Text.txt");

	if (!in_file.is_open())
	{
		std::cerr << "File could not be opened!" << std::endl;
		exit(EXIT_FAILURE); //Terminate the program
	}

	int playerScore{};
	std::string playerName{};

	while (!in_file.eof()) // in_file.eof() returns true at the end of the file
	{
		in_file >> playerName >> playerScore;

		std::cout << "Player Name: " << playerName << std::endl;
		std::cout << "Player Score: " << playerScore << std::endl;
	}

	in_file.close();
#endif

#if 0
	std::ifstream in_file;

	in_file.open("Text.txt");

	if (!in_file.is_open())
	{
		std::cerr << "File could not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	int playerNumber{}, playerScore{};
	std::string playerName{};

	while (in_file >> playerNumber >> playerName >> playerScore)
	{
		std::cout << "Player Number: " << playerNumber << std::endl;
		std::cout << "Player Name: " << playerName << std::endl;
		std::cout << "Player Score: " << playerScore << std::endl;
		std::cout << std::endl;
	}

	in_file.close();
#endif

#if 0
	std::ifstream in_file;

	in_file.open("Text1.txt");

	if (!in_file.is_open())
	{
		std::cerr << "File could not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string Str1{};
	std::string Str2{};

	std::getline(in_file, Str1);
	std::getline(in_file, Str2);

	std::cout << Str1 << std::endl;
	std::cout << Str2 << std::endl;

	in_file.close();
#endif

#if 0
	std::ifstream in_file;

	in_file.open("Text1.txt");

	if (!in_file.is_open())
	{
		std::cerr << "File could not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string line{};

	while (std::getline(in_file, line))
	{
		std::cout << line << std::endl;
	}

	in_file.close();
#endif

#if 0
	std::ifstream in_file;

	in_file.open("Text1.txt");

	if (!in_file.is_open())
	{
		std::cerr << "File could not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	char next{};

	while (in_file.get(next))
	{
		std::cout << next;
	}

	in_file.close();
#endif

#if 1
	std::ifstream in_file;

	in_file.open("Text1.txt");

	if (!in_file.is_open())
	{
		std::cerr << "File could not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	char line[40]{};

	while (in_file.getline(line, 40))
	{
		std::cout << line << std::endl;
	}

	in_file.close();
#endif


#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}