#include <iostream>

using namespace std;

int myAbs(int num);
double myAbs(double num);
int getGreatestOfTwoInts(int a, int b);
int getGreatestOfThreeInts(int a, int b, int c);
int boostHealth(int health, int healthBoost);
bool isEqual(int, int);
void logInt(int y);


int myAbs(int num)
{
	if (num < 0)
	{
		return num * -1;
	}
	return num;
}

double myAbs(double num)
{
	if (num < 0)
	{
		return num * -1;
	}
	return num;
}

int getGreatestOfTwoInts(int a, int b)
{
	return a > b ? a : b;
}

int getGreatestOfThreeInts(int a, int b, int c)
{
	// if (a > b)
	// {
	// 	if (a > c)
	// 	{
	// 		return a;
	// 	}
	// }
	// else
	// {
	// 	if (b > c)
	// 	{
	// 		return b;
	// 	}
	// 	return c;
	// }

	return getGreatestOfTwoInts(a, getGreatestOfTwoInts(b, c));
}

int boostHealth(int health, int healthBoost = 15)
{
	return health + healthBoost;
}

// int x = 5;
// int square()
// {
// 	x = x * x;
// 	return x;
// }

bool isEqual(int x, int y)
{
	return (x == y);
}

void logInt(int y = 0)
{
	cout << y << endl;
}

void welcomeMessage()
{
	cout << "welcome" << endl;
	cout << "you can died" << endl;
}

struct StructName2
{
	int x;
	float y;
	float z = 12;

	void toString() { cout << "I'am Struct" << endl; }
}demoInstance;

struct Vector2D
{
	float x = 3.0f;
	float y = 5.0f;
};

struct PlayerStats
{
	int health = 100;
	int armor = 0;
	int mana;
	int weaponDamage;
	int xp;
	int level;
	Vector2D Location;

	void setLocation(float x, float y) { Location.x = x; Location.y = y; }
	Vector2D getLocation() { return Location; }
};

struct AIStats
{
	int health;
	int weaponDamage;
	Vector2D Location;
}rat{ 100, 25, { 5 } }, alien{ 100, 50, {} };

struct Player2
{
	int Position[2]{ 1, 2 };
};


int main()
{
	/*module 101*/
	{
		//int temp = 2;
		//temp += 5 * 3; // temp = temp + (5 * 3)
		//cout << temp << endl;


		//int width = 5;
		//cout << "Width: ";
		//cin >> width;

		//int length;
		//cout << "Length: ";
		//cin >> length;

		//int area;
		//area = width * length;

		// cout << endl << "The area is: " << area << endl;

		//TODO: do something


		//int p{}, q{ 1 }, z{ 2 };
		//cout << p << endl; // 0
		//cout << q << endl;
		//cout << z << endl;

		//int x = 2147483647;
		//int x = 2147483648; // not correct
		//int x{2147483648}; // error compile

		//cout << endl << x << endl;


		//int p(0), q(1), z(2);
		//cout << p << endl;
		//cout << q << endl;
		//cout << z << endl;
		//cout << endl;


		//cout << "Size of short is: " << sizeof(short) << endl; // 2
		//cout << "Size of long is: " << sizeof(long) << endl; // 4
		//cout << "Size of long long is: " << sizeof(long long) << endl; // 4
		//cout << "Size of char is: " << sizeof(char) << endl; // 1
		//cout << "Size of int is: " << sizeof(int) << endl; // 4

		//cout << "Min value for short: " << SHRT_MIN << endl;
		//cout << "Max value for short: " << SHRT_MAX << endl;

		//32767 short
		//65535 unsigned short
		//short x(150), y(300);
		//unsigned short myShort = x * y; 

		//cout << "myShort is: " << myShort << endl;


		//int x(2), y(5), z(7);
		//int temp = 0;

		//cout << "x = " << x << "\ty = " << y << "\tz = " << z << endl;
		//cout << "++z / x = " << ++z / x << endl << endl;

		//cout << "x = " << x << "\ty = " << y << "\tz = " << z << endl;
		//cout << "x * y-- = " << x * y-- << endl << endl;

		//cout << "x = " << x << "\ty = " << y << "\tz = " << z << endl;

		// If ++Z, then ++ first and then everything else 
		// If y-- then first everything else and then ++


		//float temp = 1.3e21;
		//float temp = 0.0000000000000000000076767;

		//int a(7), b(6);
		//float sum;
		//sum = a + b; // неявное преобразование
		//float final = sum /2;
		//cout << final << endl;


		//int a(7), b(6);
		//float final = float(a + b) / 2; // явное преобразование
		//float final = static_cast<float>(a + b) / 2; // явное преобразование
		//cout << final << endl;


		//bool bEquality{false}, bInequality{false};
		//int x{}, y{};
		//cout << "Enter an integer for variable x: ";
		//cin >> x;
		//cout << "Enter an integer for variable y: ";
		//cin >> y;
		//bEquality = (x == y);
		//bInequality = (x != y);

		//cout << boolalpha;
		//cout << "Variable x equals variable y (x == y): " << bEquality << endl;
		//cout << "Variable x not equals variable y (x != y): " << bInequality << endl;
		//cout << endl;


		//int x = 5;
		//if (x > 5 && x < 10)  //if (x > 5 and x < 10)
		//{
		//	cout << x << "blablabla" << endl;
		//}


		//int x{}, y{};
		//cout << "Enter an integer for variable x: ";
		//cin >> x;
		//cout << "Enter an integer for variable y: ";
		//cin >> y;
		//cout << boolalpha;
		//cout << x << " == " << y << ": " << (x == y) << "\tand\t";
		//cout << "!(" << x << " != " << y << "): " << !(x != y) << endl;
		//cout << x << " != " << y << ": " << (x != y) << "\tand\t";
		//cout << "!(" << x << " == " << y << "): " << !(x == y) << endl;
		//cout << x << " < " << y << ": " << (x < y) << "\tand\t";
		//cout << y << " > " << x << ": " << (y > x) << endl;
		//cout << x << " <= " << y << ": " << (x <= y) << "\tand\t";
		//cout << "!(" << x << " > " << y << "): " << !(x > y) << endl;
		//cout << x << " > " << y << ": " << (x > y) << "\tand\t";
		//cout << y << " < " << x << ": " << (y < x) << endl;
		//cout << x << " >= " << y << ": " << (x >= y) << "\tand\t";
		//cout << "!(" << x << " < " << y << "): " << !(x < y) << endl;


		//char gradeSymbol = 'a';
		//cout << gradeSymbol << endl;
		//gradeSymbol = 'B';
		//cout << gradeSymbol << endl;


		// int test = 5; \
		cout << test << endl; // Экранирование сверху невидимого пробела символом \



		// int x(6), y(7), result(0);
		// result = (x > y) ? x : y;
		// cout << result << "\n";

		//int x(6), y(0), result(0);
		//result = (y != 0) ? (x / y) : 0;
		//cout << result << "\n";


		//int i = 5;
		//while (i > 0)
		//{
		//	cout << i << endl;
		//	--i;
		//}


		// int i = 5;
		// do
		// {
		// 	cout << i << endl;
		// 	--i;
		// } while (i > 0);


		//&& - and
		//|| - or

		// for (int i(1), j(2); j < 5 || i < 10; i++, j++)
		// {
		// 	cout << i << "*" << j << " = " << (i * j) << endl;
		// }


		//for (int i = 1; i < 5; i++)
		//{
		//	for (int j = 1; j < 5; j++)
		//	{
		//		cout << "i = " << i << "j = " << j << "; ";
		//	}
		//	cout << endl;
		//}


		// cout << abs(-43) << endl;
		// cout << myAbs(-43) << endl;
		// cout << myAbs(-43.5) << endl;

		// cout << getGreatestOfTwoInts(5, 3) << endl;
		// cout << getGreatestOfThreeInts(14, 4, 1) << endl;

		// int currentHealth = 25;
		// cout << "CurrentHealth is: " << boostHealth(currentHealth) << endl;


		// cout << pow(2, 2) << endl; // возводит число в заданной мощности
		// cout << sqrt(25) << endl; // вычисляет квадратный корень
		// cout << sin(16) << endl; // вычисляет синус


		//cin >> x;
		// cout << x << endl;
		// cout << x << square() << endl;


		// int x{ 5555 }, y{ 5555 };
		// if (isEqual(x, y))
		// {
		// cout << "Winner";
		// }



		// int oddArray[5] = { 1, 3, 5, 7, 9 };
		// cout << oddArray[4] << endl;

		// int oddArray[6] { 1, 3, 5, 7, 9 };
		// cin >> oddArray[5];
		// cout << oddArray[5] << endl;

		// int oddArray[6]{ 1, 2, 3, 4, 5, 6 };
		// for (int i = 0; i < 6; i++)
		// {
		// 	cout << oddArray[i] << endl;
		// }

		// int oddArray[6]{};
		// for (int i = 0; i < 6; i++)
		// {
		// 	oddArray[i] = i * 2;
		// }
		//
		// for (int i = 0; i < 6; i++)
		// {
		// 	cout << oddArray[i] << endl;
		// }

		// int oddArray[]{ 0, 2, 4, 6, 8 };
		// for (int i = 0; i < 5; i++)
		// {
		// 	cout << oddArray[i] << endl;
		// }

		// int x{}, oddArray[6]{}, y{ 5 }; // так тоже можно


		// int x{3}, y{ 5 };
		// int tempArray[x]; // Переменную для определения массива нельзя делать обычной, только const!
		// const int a = 4;
		// int tempArray[a]; // Так можно!


		// int demoArray[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		// for (int x : demoArray)
		// {
		// 	cout << x << " ";
		// }

		// auto x = 5 / 2.5f;
		// cout << x << endl;
		// cout << "Size of x is: " <<sizeof(x) << endl;


		// int demoArray[5]{};
		// for (auto x : demoArray)
		// {
		// 	cout << x << ": x" << endl;
		// 	cout << demoArray[x] << ": demoArray[x]" << endl;
		// }
		// for (auto x = 0; x < 5; x++ )
		// {
		// 	demoArray[x] = x;
		// }
		// for (auto x : demoArray)
		// {
		// 	cout << x << ": x" << endl;
		// 	cout << demoArray[x] << ": demoArray[x]" << endl;
		// }
		// Вообщем так как рэндж версия фор работает по значению,
		// то годится только для чтения массива,
		// но не для динамического заполнения!!!


		// for (auto x : { 1.0f, 2.5f })
		// {
		// 	cout << x << endl;
		// }


		// int numbers[] = {1, 2, 5};
		// cout << sizeof(numbers) << endl;
		// cout << sizeof(numbers[0]) << endl;
		// for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); ++i)
		// {
		// 	cout << sizeof(numbers) / sizeof(numbers[0]) << endl;
		// 	cout << numbers[i] << endl;
		// }


		// for (auto x : "Bob")
		// {
		// 	cout << x << endl;
		// }


		// for (auto x : "Bob is the man!")
		// {
		// 	if(x == ' ')
		// 	{
		// 		cout << "_";
		// 	}
		// 	else
		// 	{
		// 		cout << x;
		// 	}
		// }


		// const int rows = 2;
		// const int columns = 3;
		// int demo2DArray[rows][columns]
		// {
		// 	{4, 7, 8},
		// 	{6, 5, 9}
		// };
		// for (int i = 0; i < rows; i++)
		// {
		// 	for (int j = 0; j < columns; j++)
		// 	{
		// 		cout << demo2DArray[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }


		// const int rows = 2;
		// const int columns = 3;
		// int demo2DArray[rows][columns]
		// {
		// 	{4, 7, 8},
		// 	{6, 5, 9}
		// };
		// for (int j = 0; j < columns; j++)
		// {
		// 	for (int i = 0; i < rows; i++)
		// 	{
		// 		cout << demo2DArray[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }


		// int x{ 5 };
		// x++;
		// auto temp = 0.5f;
		// for (int i = 0; i <= 10; i++)
		// {
		// 	cout << i << " ";
		// }
		// cout << endl;
		// logInt(x);


		// welcomeMessage();

	}



	//struct StructName
	//{
	//	int x;
	//	float y;
	//	void toString() { cout << "I'am Struct" << endl; }
	//};

	//StructName demoInstance;
		//demoInstance.toString();

	//StructName demoInstance2{ 13, 15 };
		//cout << demoInstance2.x << endl;
		//cout << demoInstance2.y << endl;

	//demoInstance2.x = 22;
		//cout << demoInstance2.x << endl;

	//struct StructName2
		//{
		//	int x;
		//	float y;
		//
		//	void toString() { cout << "I'am Struct" << endl; }
		//}demoInstance; // можно сразу объявить объект структуры

	//demoInstance.toString();
		//cout << sizeof(demoInstance) << endl;

	// rat = alien;
		// cout << rat.weaponDamage << endl;

	// cout << "Rat Location x = " << rat.Location.x << endl;
		// cout << "Rat Location y = " << rat.Location.y << endl;
		//
		// cout << "Alien Location x = " << alien.Location.x << endl;
		// cout << "Alien Location y = " << alien.Location.y << endl;
		//
		// AIStats testAI{};
		// cout << "testAI Location y = " << testAI.Location.y << endl;
		// cout << "testAI Location y = " << testAI.Location.y << endl;

	//Player2 arrayPlayer;
		//arrayPlayer.Position[0] = {1};
		//cout << arrayPlayer.Position[0];

	// PlayerStats player1;
		// player1.setLocation(5, 45);
		// Vector2D vector = player1.getLocation();
		// cout << player1.Location.x << endl;
		// cout << vector.x << " " << vector.y << endl;;
		// cout << player1.getLocation().x << endl;


	PlayerStats player1, player2;

	PlayerStats players[] {player1, player2};

	cout << players[1].getLocation().y << endl;


	return 1;
}
