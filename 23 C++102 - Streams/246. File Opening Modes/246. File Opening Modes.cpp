// 246. File Opening Modes

#include <iostream>
#include <fstream>
#include <string>

int main()
{
#if 0
	std::ifstream in_stream{ "Tasks.txt", std::ios::in };

	if (!in_stream.is_open())
	{
		std::cerr << "Input file coul not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::ofstream out_stream{ "TodoList.txt", std::ios::out };

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
	std::ifstream in_stream{ "Tasks.txt", std::ios::in };

	if (!in_stream.is_open())
	{
		std::cerr << "Input file coul not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	//std::ofstream out_stream{ "TodoList.txt", std::ios::app };
	std::ofstream out_stream{ "TodoList.txt", std::ios::trunc };


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
	std::ifstream in_stream{ "Tasks.txt", std::ios::in };

	if (!in_stream.is_open())
	{
		std::cerr << "Input file coul not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::ofstream out_stream{ "TodoList.txt", std::ios::out | std::ios::app };

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

#if 1
	std::ifstream in_stream{ "Tasks2.txt", std::ios::in };

	if (!in_stream.is_open())
	{
		std::cerr << "Input file coul not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	//std::ofstream out_stream{ "CompletedTodoList.txt", std::ios::out };
	std::ofstream out_stream{ "CompletedTodoList.txt", std::ios::in | std::ios::ate };

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

	long pos = long(out_stream.tellp());

	//out_stream.seekp(-5, std::ios_base::end);
	out_stream.seekp(pos-5);
	out_stream << "The whole Mob!" << std::endl;

	in_stream.close();
	out_stream.close();
#endif


#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}