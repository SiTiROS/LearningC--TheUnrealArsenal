// 187. Callbacks
#include <iostream>
#include <functional>

using namespace std;

//example1
namespace example1
{
	void display(int p) { cout << p << '\t'; }

	void printScores(const int scoresP[], int sizeP, void(*fp_display)(int))
	{
		cout << "The scores are:" << endl;

		for (int i = 0; i < sizeP; i++)
		{
			fp_display(scoresP[i]);
		}
		cout << endl;
	}
}


//example2
namespace example2
{
	class Addition_Functor
	{
	public:
		int operator()(const int lho, const int rho) const { return (lho + rho); }
	};

	int add(const int lho, const int rho) { return (lho + rho); }

	// Perform a binary operation per element.
	// The first operand is the element in the array, the second operand is passed in
	template<typename Modifier>
	void modifyElements(int arrayP[], int arraysizeP, int secondOperandP, Modifier modifyP)
	{
		for (int i = 0; i < arraysizeP; i++)
		{
			arrayP[i] = modifyP(arrayP[i], secondOperandP); // посути это и есть callback
		}
	}
}


//example3
namespace example3
{
	void printNum(const int numP) { cout << numP << endl; }

	int add(const int lho, const int rho) { return (lho + rho); }

	struct Addition_Functor
	{
		int operator()(const int lho, const int rho) const { return (lho + rho); }
	};

	auto lambda = [](const int lho, const int rho) { return (lho * rho); };
}


//example4
namespace example4
{
	int add(const int lho, const int rho) { return (lho + rho); }

	struct Addition_Functor
	{
		int operator()(const int lho, const int rho) const { return (lho + rho); }
	};

	auto lambda = [](const int lho, const int rho) { return (lho * rho); };
}


//example5
namespace example5
{
	class Addition_Functor
	{
	public:
		int operator()(const int lho, const int rho) const { return (lho + rho); }
	};

	int add(const int lho, const int rho) { return (lho + rho); }

	void modifyElements(int arrayP[], int arraysizeP, int secondOperandP,
		std::function<int(const int, const int)> modifyP)
	{
		for (int i = 0; i < arraysizeP; i++)
		{
			arrayP[i] = modifyP(arrayP[i], secondOperandP); // посути это и есть callback
		}
	}
}


int main()
{
#if 0
	using namespace example1;

	const int ARRAY_SIZE = 3;
	int scores[ARRAY_SIZE]{ 72, 58, 51 };

	printScores(scores, ARRAY_SIZE, display); // посути это и есть callback
#endif

#if 0
	using namespace example2;

	const int ARRAY_SIZE = 3;
	int victoryPoints[ARRAY_SIZE]{ 1, 3, 5 };

	cout << "--- Victory Points before modification ---" << endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << victoryPoints[i] << ' ';
	}

	auto lambda = [](const int lho, const int rho) {return (lho * rho); };

	//modifyElements(victoryPoints, ARRAY_SIZE, 5, add);
	//modifyElements(victoryPoints, ARRAY_SIZE, 5, lambda);
	modifyElements(victoryPoints, ARRAY_SIZE, 5, std::plus<int>());

	cout << "\n\n--- Victory Points following modification ---" << endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << victoryPoints[i] << ' ';
	}
#endif

#if 0
	using namespace example3;

	std::function<void(const int)> display = printNum;
	display(55);
#endif

#if 0
	using namespace example4;

	std::function<int(const int, const int)> func; // обёртка
	//func = add;
	func = Addition_Functor(); // скобки () нужны потому что создается объект, так как его я не создал
	//func = lambda;

	cout << func(2, 3) << endl;
#endif

#if 1
	using namespace example5;

	const int ARRAY_SIZE = 3;
	int victoryPoints[ARRAY_SIZE]{ 1, 3, 5 };

	cout << "--- Victory Points before modification ---" << endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << victoryPoints[i] << ' ';
	}

	auto lambda = [](const int lho, const int rho) {return (lho * rho); };

	//modifyElements(victoryPoints, ARRAY_SIZE, 5, std::multiplies<int>());
	//modifyElements(victoryPoints, ARRAY_SIZE, 5, Addition_Functor());
	//modifyElements(victoryPoints, ARRAY_SIZE, 5, add);
	modifyElements(victoryPoints, ARRAY_SIZE, 5, lambda);

	cout << "\n\n--- Victory Points following modification ---" << endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << victoryPoints[i] << ' ';
	}
#endif

#if 0
#endif
	std::cout << "END" << std::endl;
	return 0;
}