// 242. Writing to a File

#include <iostream>
#include <fstream>

int main()
{
#if 0
	std::ofstream out_file{ "TodoList.txt" };

	if (!out_file.is_open())
	{
		std::cerr << "File could not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	out_file << "Feed the ducks" << std::endl;

	out_file.close();
#endif

#if 1
	std::ofstream out_file{};

	out_file.open("TodoList.txt");

	if (!out_file.is_open())
	{
		std::cerr << "File could not be opened!" << std::endl;
		exit(EXIT_FAILURE);
}

	out_file << "Feed the chikens" << std::endl;

	out_file.close();
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}