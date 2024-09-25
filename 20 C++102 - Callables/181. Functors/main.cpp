// 181. Functors

#include <iostream>

//example1
namespace E1
{
	class Square_Functor
	{
	public:
		int operator()(int p) { return (p * p); }
	};

	class Addition_Functor
	{
	public:
		Addition_Functor(int memberP) : member(memberP) {}
		int operator()(int p) { return (member + p); }

	private:
		int member;
	};

	int square(int p) { return (p * p); }
}

//example2
namespace E2
{
	class Display_Functor
	{
	public:
		void operator()(int p) { std::cout << p << "\t"; }
	};

	void display(int p) { std::cout << p << "\t"; }

	void printScores(const int scoresP[], int sizeP, Display_Functor df)
	{
		std::cout << "The scores are: ";

		for (int i = 0; i < sizeP; i++)
		{
			df(scoresP[i]);
		}
		std::cout << std::endl;
	}
}

//example3
namespace E3
{
	class Addition_Functor
	{
	public:
		Addition_Functor(int memberP) : member(memberP) {}
		int operator()(int p) { return (member + p); }

	private:
		int member;
	};

	int square(int p) { return (p * p); }
	int increment(int p) { return (p + 1); }

	template< typename T>
	void modifyElements(int pointsP[], int sizeP, T modify)
	{
		for (int i = 0; i < sizeP; i++)
		{
			pointsP[i] = modify(pointsP[i]);
		}
	}
}

int main()
{
#if 0
	using namespace E1;

	Square_Functor squareFunc;

	std::cout << square(5) << std::endl;
	std::cout << squareFunc(5) << std::endl;

	Addition_Functor additionFunc(2);
	std::cout << additionFunc(5) << std::endl;

#endif

#if 0
	using namespace E2;

	const int ARRAY_SIZE = 5;
	int scores[ARRAY_SIZE]{ 72, 68, 51 };

	Display_Functor displayFunc;
	printScores(scores, ARRAY_SIZE, displayFunc);

	printScores(scores, ARRAY_SIZE, Display_Functor{});
	printScores(scores, ARRAY_SIZE, Display_Functor());

#endif

#if 1
	using namespace E3;

	const int ARRAY_SIZE = 5;
	int victoryPoints[ARRAY_SIZE]{ 1, 3, 5 };

	std::cout << "--- Victory Point before modification ---" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << victoryPoints[i] << ' ';
	}
	std::cout << std::endl << std::endl;

	modifyElements(victoryPoints, ARRAY_SIZE, Addition_Functor(5));
	std::cout << "--- Victory Point following modification ---" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << victoryPoints[i] << ' ';
	}
	std::cout << std::endl << std::endl;

	modifyElements(victoryPoints, ARRAY_SIZE, square);
	std::cout << "--- Victory Point following modification ---" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << victoryPoints[i] << ' ';
	}
	std::cout << std::endl << std::endl;

#endif

	std::cout << "END\n";
	return 0;
}