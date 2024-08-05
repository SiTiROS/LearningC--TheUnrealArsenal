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

namespace L163
{
	using namespace std;

	struct Entity
	{
		int member;

		bool operator<(const Entity& rho) const
		{
			return this->member < rho.member;
		}
	};

	template<typename T>
	T smallest(T xP, T yP)
	{
		return (xP < yP) ? xP : yP;
	}

	template<typename T>
	void print(T param)
	{
		cout << param << endl;
	}

	ostream& operator<<(ostream& output, const Entity& entityP)
	{
		output << entityP.member;
		return output;
	}
}

namespace L164
{
	using namespace std;


}

namespace L164
{
	using namespace std;


}

namespace L165
{
	using namespace std;


}

namespace L166
{
	using namespace std;


}


int main()
{
	// 162. An Introduction to Function Templates
	{
		//using namespace L162;

		//print<int>(22);
		//print(22);

		//print('H');
		//print<char>('H');

		//print(35.5555f);
		//print<float>(35.5555f);

		//print(65.5555);
		//print<double>(65.5555);

		////
		//cout << smallest(3, 3) << endl;

		////
		//int a = 5;
		//int b = 10;

		//cout << a << '\t' << b << endl;
		//interchange(a, b);
		//cout << a << '\t' << b << endl;

		////
		//print<int, float>(2, 54.0f);
		//
		//print('H', 54);
	}


	// 163. Function Templates with Class or Struct Type Arguments
	{
		using namespace L163;

		Entity entity1{ 22 };
		Entity entity2{ 11 };

		//Entity entity3 = smallest(entity1, entity2);
		//cout << entity3.member << endl;

		cout << smallest<Entity>(entity1, entity2);

		print(entity2);
	}


	std::cout << "\nEND!\n";

	return 0;
}