#include <iostream>

//178. Function Pointers as Formal Parameters

//example1
void run() { std::cout << "Imma runnin'" << std::endl; }

void walk() { std::cout << "Imma walkin'" << std::endl; }

void remapKey(void (*&btnToRemap)(), void (*btnAction)())
{
	//std::cout << btnToRemap << std::endl;
	//std::cout << btnAction << std::endl;
	//*& - это ссылка на указатель
	btnToRemap = btnAction;
}


//example2
void display(int p) { std::cout << p << "\t"; }

void printScores(const int scoresP[], int sizeP, void(*displayFP)(int))
{
	//std::cout << displayP << std::endl;

	std::cout << "The scores are: ";

	for (int i = 0; i < sizeP; i++)
	{
		//std::cout << scoresP[i] << "\t";
		displayFP(scoresP[i]);
	}
	std::cout << std::endl;
}


int main()
{
#if 0
	void (*fp_UpArrowBtn)() = walk;
	//std::cout << fp_UpArrowBtn << std::endl;

	// Register Up Arrow Button
	remapKey(fp_UpArrowBtn, run);

	// Press Up Arrow Button
	fp_UpArrowBtn();
	fp_UpArrowBtn();
#endif

#if 1
	const int ARRAY_SIZE = 5;
	int scores[ARRAY_SIZE]{ 72, 68, 51 };

	printScores(scores, ARRAY_SIZE, display);
#endif



#if 0
#endif

	std::cout << "END\n";
	return 0;
}