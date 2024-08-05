#include <iostream>
#include <utility>

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

	template<typename T>
	class Entity
	{
	public:
		Entity(T memberP) : member(memberP) {}

		void setMember(T memberP) { member = memberP; }

		T getMember() { return member; }

	private:
		T member;
	};
}

namespace L164v2
{
	using namespace std;

	template<typename T>
	class Entity
	{
	public:
		Entity(T memberP);

		~Entity();

		void setMember(T memberP);

		T getMember();

	private:
		T member;
	};

	template<typename T>
	Entity<T>::Entity(T memberP) : member(memberP)
	{
		cout << "Constructor invoked" << endl;
	}

	template<typename T>
	Entity<T>::~Entity()
	{
		cout << "Destructor invoked" << endl;
	}

	template<typename T>
	void Entity<T>::setMember(T memberP)
	{
		member = memberP;
	}

	template<typename T>
	T Entity<T>::getMember()
	{
		return member;
	}

	//
	template<typename T1, typename T2>
	struct Pair
	{
		T1 first;
		T2 second;
	};
}

namespace L165
{
	using namespace std;


}

namespace L166
{
	using namespace std;


}

namespace L167
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
		//using namespace L163;

		//Entity entity1{ 22 };
		//Entity entity2{ 11 };

		////Entity entity3 = smallest(entity1, entity2);
		////cout << entity3.member << endl;

		//cout << smallest<Entity>(entity1, entity2);

		//print(entity2);
	}


	// 164. Class Templates
	{
		//using namespace L164;

		//Entity<int> entity1(55);

		//cout << entity1.getMember() << endl;

		//entity1.setMember(3);

		//cout << entity1.getMember() << endl;
	}

	{
		using namespace L164v2;

		//Entity<int> entity1(55);

		//cout << entity1.getMember() << endl;

		//entity1.setMember(3);

		//cout << entity1.getMember() << endl;


		//
		//Pair<int, char> pair1{44, 'H'};

		//cout << pair1.first << endl;
		//cout << pair1.second << endl;
	}

	{
		using std::pair;

		pair<char, int> pair1{'H', 55};
		pair<char, int> pair2{'B', 33};

		std::cout << pair1.first << std::endl;
		std::cout << pair1.second << std::endl;

		pair1.swap(pair2);

		std::cout << pair1.first << std::endl;
		std::cout << pair1.second << std::endl;
	}

	std::cout << "\nEND!\n";

	return 0;
}