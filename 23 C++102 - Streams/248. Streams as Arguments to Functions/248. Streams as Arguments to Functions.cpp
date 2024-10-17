// 248. Streams as Arguments to Functions

#include <iostream>
#include <fstream>
#include <cstdlib> //for exit()
#include <iomanip> //for setw()


void formatFile(std::ifstream& rawFile, std::ofstream& outputFile)
{
	outputFile.setf(std::ios::fixed);
	outputFile.setf(std::ios::showpos);
	outputFile.setf(std::ios::showpoint);

	outputFile << std::left;

	double next{};
	while (rawFile >> next)
	{
		outputFile << std::setw(10) << next << std::endl;
	}

	std::cout << "\n--- Raw File Formatting Completed ---" << std::endl;
}


int main()
{
#if 1
	std::ifstream in_stream{};

	in_stream.open("RawData.txt");

	if (!in_stream.is_open())
	{
		std::cerr << "Input file coul not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::ofstream out_stream{ "Data.txt", std::ios::out };

	if (!out_stream.is_open())
	{
		std::cerr << "Output file coul not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	formatFile(in_stream, out_stream);

	in_stream.close();
	out_stream.close();
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}