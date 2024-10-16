// 243. File Input and Output Integer Sum Exercise

#include <iostream>
#include <fstream>
#include <string>

int main()
{
#if 0 // my old variant
	std::ifstream in_file;
	std::ofstream out_file{};

	in_file.open("integers.txt");
	out_file.open("out.txt");

	if (!in_file.is_open())
	{
		std::cerr << "File could not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	if (!out_file.is_open())
	{
		std::cerr << "File could not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	const int array_size = 10;
	int arrP[array_size]{};
	std::string line{};

	int numInt{};
	int index{};
	int result{};

	std::cout << "Enter the number of integers in the file to sum:";
	std::cin >> numInt;

	while (std::getline(in_file, line))
	{
		std::cout << line << std::endl;
		arrP[index] = std::stoi(line);
		index++;
	}
	std::cout << std::endl;

	for (size_t i = 0; i < numInt; i++)
	{
		result += arrP[i];
		std::cout << result << std::endl;
	}

	out_file << result << std::endl;

	in_file.close();
	out_file.close();
#endif

#if 0 // my variant
	std::string line{};
	int sumInt{};
	int result{};

	std::ifstream in_file;
	std::ofstream out_file{};

	in_file.open("integers.txt");
	out_file.open("out.txt");

	if (!out_file.is_open() && !in_file.is_open())
	{
		std::cerr << "File could not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "Enter the number of integers in the file to sum:";
	std::cin >> sumInt;

	//bool success = !!std::getline(in_file, line);
	//bool success = static_cast<bool>(std::getline(in_file, line));

	for (size_t i = 0; i < sumInt; i++)
	{
		if (std::getline(in_file, line))
		{
			result += std::stoi(line);
		}
	}
	std::cout << std::endl;

	out_file << result << std::endl;
	std::cout << result << std::endl;

	in_file.close();
	out_file.close();
#endif

#if 1
	int numsToSum{ 0 };
	std::cout << "Enter the number of integers in the file to sum:";
	std::cin >> numsToSum;

	std::ifstream in_stream;

	in_stream.open("integers.txt");

	if (!in_stream.is_open())
	{
		std::cerr << "Input file could not be opened!" << std::endl;
		return 1;
	}

	int sum{ 0 };
	for (int i = 0; i < numsToSum; i++)
	{
		int temp{ 0 };
		if (in_stream >> temp)
		{
			std::cout << temp << std::endl;
			sum += temp;
		}
		else
		{
			break;
		}
	}

	std::cout << sum;

	std::ofstream out_stream;

	out_stream.open("out.txt");

	if (!out_stream.is_open())
	{
		std::cerr << "Output file could not be opened!" << std::endl;
		return 1;
	}

	out_stream << sum;

	in_stream.close();
	out_stream.close();
#endif


#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}