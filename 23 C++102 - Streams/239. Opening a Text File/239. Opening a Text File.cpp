// 239. Opening a Text File

#include <iostream>
#include <fstream>

int main()
{
#if 0
	std::ifstream in_file;

	in_file.open("text.txt");
	//in_file.open("D:\\C++\\LearningC--TheUnrealArsenal\\23 C++102 - Streams\\239. Opening a Text File\\text.txt");

	if (!in_file.is_open())
	{
		std::cerr << "File could not be opened!" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "File opened secessfully!" << std::endl;
	}

	in_file.close();
#endif

#if 1
	std::ifstream in_file{ "text.txt" };

	if (!in_file.is_open())
	{
		std::cerr << "File could not be opened!" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "File opened secessfully!" << std::endl;
	}

	in_file.close();
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}