#include <iostream>

namespace L162
{
	using namespace std;

	//void print(int formalP) { cout << formalP << endl; }
	//void print(char formalP) { cout << formalP << endl; }
	//void print(float formalP) { cout << formalP << endl; }
	//void print(double formalP) { cout << formalP << endl; }

	template<typename T>
	void print(T formalP1) { cout << formalP1 << endl; }

	template<typename T>
	T smallest(T xP, T yP)
	{
		return (xP < yP) ? xP : yP;
	}

	template<typename T>
	void interchange(T& xP, T& yP)
	{
		T temp;
		temp = xP;
		xP = yP;
		yP = temp;
	}

	template<typename T1, typename T2>
	void print(T1 param1, T2 param2)
	{
		cout << "Argument 1: " << param1 << endl;
		cout << "Argument 2: " << param2 << endl;
	}

}

int main()
{
	// 162. An Introduction to Function Templates
	{
		using namespace L162;

		print<int>(22);
		print(22);

		print('H');
		print<char>('H');

		print(35.5555f);
		print<float>(35.5555f);

		print(65.5555);
		print<double>(65.5555);

		//
		cout << smallest(3, 3) << endl;

		//
		int a = 5;
		int b = 10;

		cout << a << '\t' << b << endl;
		interchange(a, b);
		cout << a << '\t' << b << endl;

		//
		print<int, float>(2, 54.0f);
		
		print('H', 54);
	}


	std::cout << "\nEND!\n";

	return 0;
}