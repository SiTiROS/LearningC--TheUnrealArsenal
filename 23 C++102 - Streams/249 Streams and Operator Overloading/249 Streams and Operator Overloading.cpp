// 249 Streams and Operator Overloading

#include <iostream>
#include <fstream>

class Entity
{
	friend std::ostream& operator<<(std::ostream& output, const Entity& entityP);
	friend std::istream& operator>>(std::istream& input, Entity& entityP);

public:
	Entity(int memberP = 5)
		:member(memberP)
	{}

private:
	int member;
};

std::ostream& operator<<(std::ostream& output, const Entity& entityP)
{
	output << entityP.member;
	return output;
}

std::istream& operator>>(std::istream& input, Entity& entityP)
{
	input >> entityP.member;
	return input;
}


int main()
{
#if 0
	Entity entity1{};

	std::cout << "Enter integer to storage in the Entity object: ";
	std::cin >> entity1;

	std::cout << "The integer in the Entity object is: ";
	std::cout << entity1 << std::endl;
#endif

#if 1
	Entity entity1{};

	std::ifstream in_stream{};

	in_stream.open("Integers.txt");

	if (!in_stream.is_open())
	{
		std::cerr << "Input file coul not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	in_stream >> entity1;
	std::cout << "Integer extractedd from file. ";
	std::cout << "Data to be stored in the Entity object." << std::endl;

	std::ofstream out_stream{};

	out_stream.open("Out.txt");

	if (!out_stream.is_open())
	{
		std::cerr << "Output file coul not be opened!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "The integer in the Entity object is: ";
	std::cout << entity1 << std::endl;
	out_stream << entity1 << std::endl;

	in_stream.close();
	out_stream.close();
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}