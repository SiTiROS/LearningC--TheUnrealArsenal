// 244. Opening User Specified Files

#include <iostream>
#include <fstream>
#include <string>

int main()
{
#if 0
	char fileName[21]{};

	std::cout << "Enter the name of an existing file: ";

	std::cin >> fileName;

	std::ifstream in_stream{};

	in_stream.open(fileName);

	if (!in_stream.is_open())
	{
		std::cerr << "Input file \'" << fileName << "\' could not be opened!" << std::endl;
		return 1;
	}

	int data;

	while (in_stream >> data)
	{
		std::cout << data << std::endl;
	}
#endif

#if 1
	std::string fileName{};

	std::cout << "Enter the name of an existing file: ";

	std::cin >> fileName;

	std::ifstream in_stream{};

	in_stream.open(fileName);

	if (!in_stream.is_open())
	{
		std::cerr << "Input file \'" << fileName << "\' could not be opened!" << std::endl;
		return 1;
	}

	int data;

	while (in_stream >> data)
	{
		std::cout << data << std::endl;
	}

	in_stream.close();

#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}