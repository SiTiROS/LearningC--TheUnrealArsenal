// 247. The fstream Class

#include <iostream>
#include <fstream>
#include <string>

int main()
{
#if 0
	std::fstream in_stream{ "Tasks.txt", std::ios::in };

	if (!in_stream.is_open())
	{
		std::cerr << "Input file coul not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::fstream out_stream{ "TodoList.txt", std::ios::out | std::ios::app };

	if (!out_stream.is_open())
	{
		std::cerr << "Output file coul not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string line{};

	while (std::getline(in_stream, line))
	{
		out_stream << line << std::endl;
	}

	in_stream.close();
	out_stream.close();
#endif

#if 0
	std::fstream file_stream{ "Tasks.txt", std::ios::in | std::ios::out | std::ios::app };

	if (!file_stream.is_open())
	{
		std::cerr << "File coul not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "\n--- Tasks ---" << std::endl;

	std::string line{};

	while (std::getline(file_stream, line))
	{
		std::cout << line << std::endl;
	}

	file_stream.clear();
	file_stream << "\nJump 10 times to go home early!";

	file_stream.close();
#endif

#if 1
	auto Mode = std::ios::in | std::ios::out | std::ios::app;
	std::fstream file_stream{ "Tasks.txt", Mode};

	if (!file_stream.is_open())
	{
		std::cerr << "File coul not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "\n--- Tasks ---" << std::endl;

	std::string line{};

	while (std::getline(file_stream, line))
	{
		std::cout << line << std::endl;
	}

	file_stream.clear();
	file_stream << "\nJump 10 times to go home early!";

	file_stream.close();
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}