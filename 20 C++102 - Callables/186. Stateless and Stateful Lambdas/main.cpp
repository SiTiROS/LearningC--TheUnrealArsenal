// 186. Stateless and Stateful Lambdas
#include <iostream>
using namespace std;

// example2
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

// example3
void printScores_if(const int scoresP[], int sizeP, bool(*fp_Predicate)(int))
{
	cout << "The scores are:" << endl;

	for (int i = 0; i < sizeP; i++)
	{
		if(fp_Predicate(scoresP[i]))
		{
			cout << scoresP[i] << '\t';
		}
	}
	cout << endl;
}

int main()
{
#if 0
	int x{ 3 }, y{ 5 };

	//stateless - без состояния
	[](int x) {cout << x << endl; }(55);
	[](int& x) {cout << x << endl; }(x);
	[](const int& x) {cout << x << endl; }(x);

	//stateful - с состоянием
	auto lambda = [x, y](int p1, int p2)
	{
		cout << "Parameters... " << endl;
		cout << p1 << '\t' << p2 << endl;

		cout << "Captured... " << endl;
		cout << x << '\t' << y << endl;
	};

	lambda(1, 2);
#endif

#if 0
	const int ARRAY_SIZE = 3;
	int scores[ARRAY_SIZE]{ 72, 68, 51 };

	printScores(scores, ARRAY_SIZE, [](int p) {cout << p << '\t'; });
	printScores(scores, ARRAY_SIZE, display); // посути тоже самое

	//printScores(scores, ARRAY_SIZE, [ARRAY_SIZE](int p) {cout << p << '\t'; }); так работать не будет
#endif

#if 1
	const int ARRAY_SIZE = 3;
	int scores[ARRAY_SIZE]{ 72, 68, 51 };

	//display evens
	printScores_if(scores, ARRAY_SIZE, [](int p) { return p % 2 == 0; });

	//display odds
	printScores_if(scores, ARRAY_SIZE, [](int p) { return p % 2 != 0; });
#endif

#if 0
#endif
	std::cout << "END" << std::endl;
	return 0;
}