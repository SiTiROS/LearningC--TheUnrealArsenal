#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef int* PtrInt;
typedef unsigned long long Distance;
typedef const int* const ConstPtrConstInt;

using PtrInt2 = int*;

void print()
{
	using ullong = unsigned long long;
	ullong distance = 50000000;

	cout << distance << endl;
}

void gameLoop();

// struct PlayerStats
// {
// 	int score;
// };
//
// PlayerStats* GetPlayerWithGreatestScore(PlayerStats* pl1, PlayerStats* pl2)
// {
// 	if (pl1->score > pl2->score)
// 		return pl1;
// 	else if (pl2->score > pl1->score)
// 		return pl2;
// 	else
// 		return nullptr;
// }

// struct PlayerStats
// {
// 	int health;
// 	int armor;
// 	int mana;
// 	int weaponDamage;
// 	int xp;
// 	int level;
// }player1, player2;

// struct GameStats
// {
// 	int currentLevel = 3;
//
// 	int getCurrentLevel()
// 	{
// 		return currentLevel;
// 	}
// };

// void swapInts(int& p, int& q)
// {
// 	int temp = p;
// 	p = q;
// 	q = temp;
// }

// void inputScores(int& x, int& y, int& z)
// {
// 	cout << "Enter scores for the past 3 games: " << endl;
// 	cin >> x >> y >> z;
// }

// float getAverageScore(const int& x, const int& y, const int& z)
// {
// 	return (x + y + z) / 3.0f;
// }

// int& getInt()
// {
// 	static int temp = 10;
// 	temp++;
//
// 	return temp;
// }

// void printScore(const int& x)
// {
// 	cout << x << endl;
// }
//
// void printScore(int&& x)
// {
// 	x = 92;
// 	cout << x << endl;
// }

// void incrementScore(int* const x)
// {
// 	(*x)++;
// 	cout << *x << endl;
// }

// void printScore(const int* const x)
// {
// 	cout << *x << endl;
// }

// int generateRandomSize(int i)
// {
// 	srand(time(0));
// 	return rand() % i + 1;
// }

//const int SIZE = 3;

// void inputScores(int scoresP[])
// {
// 	cout << "Enter " << SIZE << " scores: ";
// 	for (int i = 0; i < SIZE; i++)
// 	{
// 		cin >> scoresP[i];
// 	}
//
// 	//cout << sizeof(scoresP) << endl;
// }

// void printScore(int scoresP[])
// {
// 	cout << "--------------- " << endl;
// 	cout << "The score are: ";
//
// 	scoresP[0] = 300; 
// 	for (int i = 0; i < SIZE; i++)
// 	{
// 		cout << scoresP[i] << "\t";
// 	}
// 	cout << endl;
// }

// void printScore(const int* scoresP)
// {
// 	cout << "--------------- " << endl;
// 	cout << "The score are: ";
//
// 	for (int i = 0; i < SIZE; i++)
// 	{
// 		cout << *scoresP++ << "\t";
// 	}
// 	cout << endl;
// }

// void inputScores(int scoresP[], int size)
// {
// 	cout << "Enter " << size << " scores: ";
// 	for (int i = 0; i < size; i++)
// 	{
// 		cin >> scoresP[i];
// 	}
// }
//
// void printScore(const int scoresP[], int size)
// {
// 	cout << "\n--------------- " << endl;
// 	cout << "The score are: ";
//
// 	for (int i = 0; i < size; i++)
// 	{
// 		cout << scoresP[i] << "\t";
// 	}
// 	cout << endl;
// }

int* createDynamicInt()
{
	return new int(5);
}

int* createStaticArray()
{
	static int staticArray[5];

	staticArray[0] = 250;

	return staticArray;
}

int* createDynamicArray()
{
	int* dynamicArray = new int[5];

	dynamicArray[0] = 250;

	return dynamicArray;
}

unsigned long factorial(unsigned long n)
{
	if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}


int main()
{
	// int demoVar = 12;
	// cout << &demoVar << endl;
	// int *demoPtr = &demoVar;
	// cout << *demoPtr << endl;
	// cout << demoPtr << endl;
	// *demoPtr = 15; // присвоение значения через указатель
	// cout << *demoPtr << endl;
	// cout << demoPtr << endl;
	// cout << demoVar << endl;
	// cout << &demoVar << endl;


	//int demoVar = 12;
	//int *demoPtr = nullptr; // декларирование указателя на пустой адресс null
	//cout << demoPtr << endl;
	//demoPtr = &demoVar;  // уставновка указателя на адресс переменной
	//cout << demoPtr << endl;
	//cout << *demoPtr << endl; // получение значения указателя


	// int* ptr{ nullptr };
	// cout << "Pointer: " << ptr << endl;
	// cout << "Size of Pointer: " << sizeof(ptr) << endl;
	// cin.get();


	// double dbl{ };
	// double *dblPtr{ &dbl };
	// cout << sizeof dbl << endl;
	// cout << sizeof dblPtr << endl;


	// PlayerStats* stats{ &player1 };
	// PlayerStats* stats{};
	// cout << "stats: " << stats << endl;
	// cout << "&stats: " << &stats << endl;
	// stats = nullptr;
	// cout << "stats: " << stats << endl;
	// cout << "&stats: " << &stats << endl;
	// stats = &player2;
	// cout << "stats: " << stats << endl;
	// cout << "&stats: " << &stats << endl;
	//cout << sizeof player1 << endl;
	//cout << sizeof stats << endl;


	// int i = 1;
	// double d = 1.5;
	// void* ptr = &i;
	// ptr = &d;
	// //*ptr = 5.5; // так не будет работать ибо указатель типа void
	// *(double*)ptr = 5.5; // нужен cast чтобы указатель типа void разыменовать
	// cout << *(double*)ptr << endl;
	// cout << (double*)ptr << endl;

	// void* ptr = nullptr;
	// short i = 129;
	// ptr = &i;
	// short y = *(short*)ptr;
	// cout << y << endl;


	// int x{ 12 }, y{ 999 };
	// const int* ptr{ &x };
	// ptr = &y; //можно!
	// *ptr = 15;//нельзя!

	// int x{ 12 }, y{ 999 };
	// int* const ptr{ &x };
	// ptr = &y; //нельзя!
	// *ptr = 15; //можно!

	// int x{ 12 }, y{ 999 };
	// const int* const ptr{ &x };
	// ptr = &y; //нельзя!
	// *ptr = 15; //нельзя!

	// int x{ 12 }, y{ 999 };
	// const int* const ptr{ &x };
	// cout << *ptr << endl;

	// const int DEMO_CONSTANT{ 12 };
	// int y { 999 };
	// //int* ptr { &y };
	// //int* ptr { &DEMO_CONSTANT }; // нельзя
	// const int* ptr { &DEMO_CONSTANT };
	// //*ptr = 12;
	// cout << *ptr << endl;


	// int demoArray[]{1, 2, 3};
	//
	// cout << demoArray << endl;
	// cout << &demoArray[0] << endl;
	// cout << &demoArray[1] << endl;
	// cout << &demoArray[2] << endl;
	// cout << *demoArray << endl;
	// cout << demoArray[2] << endl;
	//
	// int* ptr { demoArray };
	// cout << ptr << endl;
	// cout << *ptr << endl;
	// cout << ptr[2] << endl;
	// cout << &ptr[2] << endl;


	// char demoChar{ 'b' };
	//
	// int demoArray[]{ 1, 555555555, 3 };
	// cout << &demoArray[0] << endl;
	// cout << &demoArray[1] << endl;
	// cout << &demoArray[2] << endl;


	// int x{ 12 }, y{ 999 };
	//
	// int* ptr = &x;
	// int& x_Ref = x;
	//
	// //x_Ref = 25;
	// //*ptr = 26;
	// ptr = &y;
	//
	// x_Ref = y;
	// //x_Ref = 500; 
	//
	// cout << "x: " << x << endl;
	// cout << &x << endl;
	//
	// cout << "x_Ref: " << x_Ref << endl;
	// cout << &x_Ref << endl;
	//
	// cout << "*ptr: " << *ptr << endl;
	// cout << ptr << endl;


	// int demoArray[] = {1, 2, 3};
	//
	// for (int &temp: demoArray)
	// {
	// 	temp = 55;
	// }
	//
	// for (int const &temp: demoArray)
	// {
	// 	cout << temp << endl;
	// }

	// int demoArray[] = { 7, 2, 7 };
	//
	// int i = 0;
	// for (int& temp : demoArray)
	// {
	// 	cout << &demoArray[i] << endl;
	// 	cout << &temp << endl;
	//
	// 	cout << " --------- " << endl;
	// 	i++;
	// }
	//
	// for (int const& temp : demoArray)
	// {
	// 	cout << temp << endl;
	// }


	// int x{ 12 }, y{ 999 };
	//
	// int* ptr = &x;
	// int& x_Ref = x;
	//
	// ptr = &y;
	//
	// x_Ref = y; // ссылка на x не стала ссылкой на y. т.е 1 раз проинициилизировал и всё, больше изменить нельзя!
	// //x_Ref = 500; // ссылка на x не стала ссылкой на y
	//
	// cout << "x: " << x << endl;
	// cout << &x << endl;
	//
	// cout << "x_Ref: " << x_Ref << endl;
	// cout << &x_Ref << endl;
	//
	// cout << "*ptr: " << *ptr << endl;
	// cout << ptr << endl;


	// const int& literalRef = 1;
	//
	// cout << literalRef << endl;
	// cout << &literalRef << endl;


	// int x{ 5 }, y{ 15 }, *ptr1{ &x }, *ptr2{ nullptr };
	//
	// //ptr2 = ptr1;
	// ptr2 = &y;
	//
	// cout << *ptr2 << endl;
	//
	// if (ptr1 == ptr2)
	// {
	// 	cout << "true" << endl;
	// }
	// else
	// {
	// 	cout << "false" << endl;
	// }


	// int demoArray[]{ 2, 4, 6, 8 };
	// int* ptr1{ demoArray };
	//
	// *(ptr1 + 1) = 700;
	// *(demoArray + 2) = 7;
	//
	// cout << *(demoArray + 1) << ": ";
	// cout << (demoArray + 1) << endl;
	// cout << *(ptr1 + 2) << ": ";
	// cout << (ptr1 + 2) << endl;
	// cout << "-----------" << endl;
	//
	// for (const auto& demo_array : demoArray)
	// {
	// 	cout << demo_array << ": ";
	// 	cout << &demo_array << endl;
	// }


	// int x{ 5 }, y{ 97 };
	//
	// int* ptr{&x};
	// ptr[0] = 3;
	//
	// cout << ptr[0] << endl;
	// cout << ptr[1] << endl;
	// cout << ptr[2] << endl;
	//
	// cin.get();


	// int demoArray[]{ 1, 2, 3 };
	// int* ptr1{ demoArray };
	//
	// //demoArray[1] = 5;
	// *(ptr1 + 1) = 5;
	// //*(demoArray + 1) = 5;
	//
	// cout << &demoArray[1] << endl;
	// cout << (demoArray + 1) << endl;
	// cout << (ptr1 + 1) << endl;
	//
	// cout << demoArray[1] << endl;
	// cout << *(demoArray + 1) << endl;
	// cout << *(ptr1 + 1) << endl;


	// int demoArray[]{ 2, 4, 6 };
	// int* ptr1{ demoArray };
	//
	// //*(int*)((char*)ptr1 + 4) = 700; //cast(c style) in char and offset 4 byte
	// //*reinterpret_cast<int*>(reinterpret_cast<char*>(ptr1) + 4) = 700; // new style cast
	//
	// //*((char*)ptr1 + 4) = 5;//cast(c style) in char and offset 4 byte
	// //*(reinterpret_cast<char*>(ptr1) + 4) = 5; // new style cast
	//
	// *(ptr1 + 1) = 700;
	// *(demoArray + 2) = 7;
	//
	// cout << demoArray[0] << endl;
	// cout << *(demoArray + 1) << endl;
	// cout << *(ptr1 + 2) << endl;
	// cout << ptr1[2] << endl;


	// int demoArray[]{ 2, 4, 6, 8, 10 };
	// int* ptr1{ demoArray + 1};
	// int* ptr2{ demoArray + 4 };
	//
	// cout << ptr1[0] << endl;
	// cout << ptr2[0] << endl;
	//
	// int offset = ptr2 - ptr1;
	//
	// //ptr = ptr + 2;
	// //ptr +=2;
	// //ptr++;
	//
	// cout << offset << endl;


	// int demoArray[]{ 2, 4, 6 };
	// int* ptr1{ nullptr };
	//
	// ptr1 = demoArray;
	//
	// // cout << *ptr1 << endl;
	// // cout << ptr1 << endl;
	// // cout << &ptr1 << endl;
	// cout << demoArray << endl;
	// cout << *demoArray << endl;
	// cout << &demoArray << endl;
	//
	// cout << sizeof demoArray << endl;
	// cout << sizeof ptr1 << endl;


	// int x{ 5 }, y{ 97 };
	// cout << "x: " << x << "\ty: " << y << endl;
	// swapInts(x, y);
	// cout << "x: " << x << "\ty: " << y << endl;


	// int score1{}, score2{}, score3{};
	// float averageScore{};
	//
	// inputScores(score1, score2, score3);
	//
	// averageScore = getAverageScore(score1, score2, score3);
	// cout << "Your average score is: " << averageScore << endl;


	// int x = 5;
	//
	// int &x_ref = x;
	// x_ref = 50; // изменяем значение по ссылке
	//
	// cout << x << endl;


	//int &x = getInt();
	//getInt() = 50;
	//getInt() += 50;
	//x += 50;
	//
	// int* ptr{&getInt()};
	// *ptr += 500;
	//
	// //getInt() += 50;
	//
	// cout << getInt();

	// int score{ 75 };
	//
	// cout << score << endl;
	//
	// printScore(score);
	// printScore(7);


	// int* ptr;
	// ptr = new int;
	// *ptr = 15;
	//
	// cout << *ptr << endl;
	// cout << ptr << endl;
	//
	// delete ptr;
	// cout << ptr << endl;
	//
	// ptr = nullptr;
	// cout << ptr << endl;


	// int arraySize{};
	// cin >> arraySize;
	//
	// int *arrayPtr = new int[arraySize];
	//
	// for (int i = 0; i < arraySize; i++)
	// {
	// 	cin >> arrayPtr[i];
	// }
	//
	// for (int i = 0; i < arraySize; i++)
	// {
	// 	cout << arrayPtr[i] << endl;
	// }
	//
	// delete [] arrayPtr;
	// arrayPtr = nullptr;


	// GameStats* game = new GameStats;
	//
	// cout << game->getCurrentLevel() << endl;
	// cout << (*game).getCurrentLevel() << endl;

	// GameStats game;
	//
	// GameStats* ptr = &game;
	//
	// cout << ptr->getCurrentLevel() << endl;


	// int score = 5;
	// int* ptr{ &score };
	//
	// //incrementScore(&score);
	// incrementScore(ptr);
	//
	// printScore(&score);
	// printScore(ptr);


	//int scores[SIZE];
	//cout << sizeof(scores) << endl;
	//
	// const int ARRAY_SIZE_1 = 3;
	// int scores1[ARRAY_SIZE_1];
	//
	// inputScores(scores1, ARRAY_SIZE_1);
	// printScore(scores1, ARRAY_SIZE_1);
	//
	// const int ARRAY_SIZE_2 = 5;
	// int scores2[ARRAY_SIZE_2]{3, 4, 6};
	//
	// printScore(scores2, ARRAY_SIZE_2);


	// int* intPtr1 = createDynamicInt();
	// int* intPtr2 = createDynamicInt();
	//
	// cout << *intPtr1 << endl;
	// cout << *intPtr2 << endl;
	//
	// *intPtr2 = 100;
	//
	// cout << *intPtr1 << endl;
	// cout << *intPtr2 << endl;
	//
	// delete intPtr1;
	// delete intPtr2;
	// intPtr1 = nullptr;
	// intPtr2 = nullptr;


	// //int* ptr = createStaticArray();
	// int* ptr = createDynamicArray();
	//
	// cout << ptr[0] << endl;
	//
	// delete[] ptr;
	//
	// cout << endl;


	// PlayerStats* player1 = new PlayerStats{ 15 };
	// PlayerStats* player2 = new PlayerStats{ 15 };
	//
	// PlayerStats* Winner = GetPlayerWithGreatestScore(player1, player2);
	//
	// if (Winner == player1)
	// {
	// 	cout << "Winner player1" << endl;
	// 	cout << Winner->score << endl;
	// }
	// else if (Winner == player2)
	// {
	// 	cout << "Winner player2" << endl;
	// 	cout << Winner->score << endl;
	// }
	// else if (Winner == nullptr)
	// {
	// 	cout << "It's a draw!" << endl;
	// }
	//
	// delete player1;
	// delete player2;


	// int a = 3;
	//
	// PtrInt c = &a;
	// PtrInt e, e1, e2;
	//
	// Distance d{500};
	//
	// cout << d << endl;
	// cout << *c << endl;


	// int demoInt{ 55 };
	//
	// ConstPtrConstInt ConstPtr{ &demoInt };
	//
	// PtrInt ptr{ ConstPtr };
	//
	// cout << *ptr << endl;


	// int demoInt{ 55 };
	// PtrInt2 c = { &demoInt };
	//
	// cout << *c << endl;
	//
	// print();


	//cout << RAND_MAX; // макс значение которое может вывести rand

	// int randomNum{};
	//
	// srand(time(nullptr));
	// for (int i = 2; i < 5; i++)
	// {
	// 	randomNum = 2 + rand() % ((i + 1) - 2);
	// 	cout << randomNum << endl;
	// }

	// int randomNum{}, rolls{ 3 };
	// int r{ 6 };
	// int lowerBound{ 1 };
	//
	// srand(static_cast<unsigned int>(time(nullptr)));
	//
	// for (int i = 0; i < rolls; i++)
	// {
	// 	randomNum = lowerBound + rand() % r;
	// 	cout << randomNum << endl;
	// }


	// cout << factorial(3) << endl;


	// int* intPtr = new int(3);
	// int* arrPtr = new int[5]{};
	//
	// cout << *intPtr << endl;
	// cout << arrPtr[2] << endl;
	//
	// delete intPtr;
	// intPtr = nullptr;
	//
	// delete[] arrPtr;
	// arrPtr = nullptr;


	gameLoop();

	return 1;
}


void gameLoop()
{
	int secretNumber{}, guess{}, tries{};
	srand(static_cast<unsigned int>(time(nullptr)));
	secretNumber = rand() % 50 + 1;

	cout << "Guess my secret number.\nThe number is between 1 and 50.\n" << endl;

	do
	{
		cout << "Your guess for try #" << ++tries << " is: ";
		cin >> guess;

		if (guess > secretNumber)
			cout << "\nToo high! Please try again..." << endl;
		else if (guess < secretNumber)
			cout << "\nToo low! Please try again..." << endl;
		else
			cout << "\nYou guessed correctly! You got it in " << tries << endl;

	} while (guess != secretNumber);

}
