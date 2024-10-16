// 245. The get(), put(), unget(), and putback() Member Functions

#include <iostream>
#include <fstream>
#include <string>

int main()
{
#if 0
	std::ifstream in_stream{};

	in_stream.open("Characters.txt");

	if (!in_stream.is_open())
	{
		std::cerr << "Input file coul not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	char c1{}, c2{}, c3{}, c4{}, c5{};

	in_stream.get(c1);
	in_stream.get(c2);
	in_stream.get(c3);
	in_stream.get(c4);

	std::cout << c1 << c2 << c3 << c4 << std::endl;

	in_stream.close();
#endif

#if 0
	std::ifstream in_stream{};

	in_stream.open("Characters.txt");

	if (!in_stream.is_open())
	{
		std::cerr << "Input file coul not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	char c1{}, c2{}, c3{}, c4{}, c5{};

	in_stream.get(c1);
	in_stream.get(c2);
	in_stream.get(c3);
	in_stream.get(c4);

	std::cout.put(c1);
	std::cout.put(c2);
	std::cout.put(c3);
	std::cout.put(c4);

	in_stream.close();
#endif

#if 0
	std::cout << "Please enter a word: ";

	//Test first character in input stream for numbers
	char c{};
	c = std::cin.get(); // delete c in stream

	if ((c >= '0') && (c <= '9'))
	{
		std::cerr << "Incorrect input!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string str{};
	//std::cin.unget(); // return c in stream
	std::cin.putback(c); // return c in stream
	std::getline(std::cin, str);

	std::cout << "Your entered: " << str << std::endl;

	//std::cout << "Your entered: " << c << str << std::endl;
#endif

#if 0 //my variant 1
	std::ifstream in_stream{};

	in_stream.open("Numbers.txt");

	if (!in_stream.is_open())
	{
		std::cerr << "Input file coul not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "The numbers are..." << std::endl;

	char c{};
	do
	{
		c = in_stream.get();
		std::cout << c;
	} while (c != ' ');
	in_stream.putback(c);

	std::string s;
	std::cout << "\nand then";
	std::getline(in_stream, s);
	std::cout << s;

	in_stream.close();
#endif

#if 0 //my variant 2
	std::ifstream in_stream{};

	in_stream.open("Numbers.txt");

	if (!in_stream.is_open())
	{
		std::cerr << "Input file coul not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "The numbers are..." << std::endl;

	char c{};
	while (true)
	{
		if (c != ' ')
		{
			c = in_stream.get();
			std::cout << c;
		}
		else
		{
			in_stream.putback(c);
			std::string s;
			std::cout << "\nand then";
			std::getline(in_stream, s);
			std::cout << s;
			break;
		}
	}

	in_stream.close();
#endif

#if 1 
	std::ifstream in_stream{};

	in_stream.open("Numbers.txt");

	if (!in_stream.is_open())
	{
		std::cerr << "Input file coul not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "The numbers are..." << std::endl;

	char next{};
	in_stream.get(next);
	while (next != ' ')
	{
		std::cout.put(next);
		in_stream.get(next);
	}

	in_stream.putback(next);

	std::cout << "\nand then";

	while (in_stream.get(next))
	{
		std::cout << next;
	}

	in_stream.close();
#endif


#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}