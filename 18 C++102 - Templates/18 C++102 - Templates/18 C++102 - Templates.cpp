#include <iostream>
#include <utility>
//#include "Entity.h"

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

	template<typename T = int>
	T* instantiate()
	{
		T* localPtr = new T(55);
		return localPtr;
	}
}

namespace L165v2
{
	using namespace std;

	template<int x, typename T = int>
	T* instantiate()
	{
		T* localPtr = new T(x);
		return localPtr;
	}
}

namespace L165v3
{
	using namespace std;

	template<typename T = int, int size = 4>
	struct ArrayEntity
	{
		void toString()
		{
			for (int i = 0; i < size; i++)
			{
				cout << m_Array[i] << endl;
			}
		}

		T m_Array[size]{};
	};
}

namespace L165v4
{
	using namespace std;

	template<typename T = int, int size = 4>
	class ArrayEntity
	{
	public:
		void toString()
		{
			for (int i = 0; i < size; i++)
			{
				cout << m_Array[i] << endl;
			}
		}

		T& operator[](int index)
		{
			return m_Array[index];
		}

	private:
		T m_Array[size]{};
	};
}

namespace L165v5
{
	using namespace std;

	enum ESize { One = 1, Two, Three };

	template<typename T, ESize size>
	class ArrayEntity
	{
	public:
		T& operator[](int index)
		{
			return m_Array[index];
		}

	private:
		T m_Array[size]{};
	};
}

namespace L165v6
{
	using namespace std;

	struct Entity { int member{}; };

	template<Entity& entity>
	struct EntityTemplate
	{
		void toString() { cout << entity.member << endl; }
	};

	static Entity entity { 55 };
}

namespace L166
{
	using namespace std;

	template<typename T, T* pT>
	struct Entity
	{
		T getVal() { return *pT; }
	};

	int x = 55;
}

namespace L166v2
{
	using namespace std;

	template<typename T, T pT>
	struct Entity
	{
		T getVal() { return pT; }
	};

	//const float x = 55.05f;
}

namespace L166v3
{
	using namespace std;

	template<typename T1, T1* pT, typename T2 = T1>
	struct Entity
	{
		T2 getVal() { return *pT; }
	};

	int x = 55;
}

namespace L167
{
	using namespace std;

	int G = 0;

	template<typename Type = int>
	void increment()
	{
		static int L = 0;
		cout << "Global Variable: " << ++G << "\tLocal Static Variable: " << ++L << endl;
	}

	template<typename Type>
	struct Entity
	{
		inline static int L = 0;

		void increment()
		{
			cout << "Global Variable: " << ++G
				<< "\tLocal Static Variable: " << ++L << endl;
		}
	};

}

namespace L168
{
	using namespace std;

	template<typename T>
	void print(T formalP);

	template<typename T>
	void print(T formalP) { cout << formalP << endl; }

	template<typename T>
	class Entity
	{
	public:
		Entity(T memberP);

		void setMember(T memberP);

		T getMember() const;

	private:
		T member;
	};

	template<typename T>
	Entity<T>::Entity(T memberP) : member(memberP) {}

	template<typename T>
	void Entity<T>::setMember(T memberP) { member = memberP; }

	template<typename T>
	T Entity<T>::getMember() const { return member; }
}

namespace L168v2
{
	using namespace std;

	//#include "Entity.cpp"
#include "Entity.h"
}

namespace L169
{
	using namespace std;

	template<typename T>
	struct Pair
	{
		T first;
		T second;
	};

	//int smallestMember(const Pair<int>& pairP)
	//{
	//	return (pairP.first < pairP.second) ? pairP.first : pairP.second;
	//}

	//template<typename T>
	//T smallestMember(const Pair<T>& pairP)
	//{
	//	return (pairP.first < pairP.second) ? pairP.first : pairP.second;
	//}

	template<typename T>
	T smallestMember(const Pair<T>* pairP)
	{
		return (pairP->first < pairP->second) ? pairP->first : pairP->second;
	}
}

namespace L169v2
{
	using namespace std;

	template<typename T>
	struct Pair
	{
		T first;
		T second;
	};

	template<typename T>
	T smallestMember(const Pair<T>& pairP)
	{
		return (pairP.first < pairP.second) ? pairP.first : pairP.second;
	}

	template<typename T>
	T addMembers(const Pair<T>& pairP)
	{
		return (pairP.first + pairP.second);
	}
}

namespace L169v3
{
	using namespace std;

	template<typename T>
	struct Pair
	{
		T first;
		T second;

		Pair operator+(const Pair& other) const
		{
			return Pair{ first + other.first, second + other.second };
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& output, const Pair<T>& pairP)
	{
		output << "First: " << pairP.first << "\t Second: " << pairP.second << endl;
		return output;
	}

	template<typename T>
	T addMembers(const Pair<T>& pairP)
	{
		return (pairP.first + pairP.second);
	}
}

namespace L170
{
	using namespace std;

	template<typename T>
	void print(T param)
	{
		cout << "---From Template--- \nArgument: " << param << endl << endl;
	}

	template<typename T1, typename T2>
	void print(T1 param1, T2 param2)
	{
		cout << "---From Template--- \nArgument1: " << param1 << endl;
		cout << "Argument2: " << param2 << endl << endl;
	}

	void print(int param)
	{
		cout << "---From print(int)--- \nArgument: " << param << endl << endl;
	}

	void print(const int* param)
	{
		cout << "---From print(const int*)--- \nArgument: " << *param << endl << endl;
	}
}

namespace L171
{
	using namespace std;

	template<typename T>
	void print(T formalP)
	{
		cout << "--- From General Template --- \nArgument: " << formalP << endl << endl;
	}

	template<>
	void print<const int*>(const int* formalP)
	{
		cout << "--- From Specialized Template --- \nArgument: " << *formalP << endl << endl;
	}

	template<typename T>
	void print(T* formalP)
	{
		cout << "--- From Template Overload --- \nArgument: " << *formalP << endl << endl;
	}

	//void print(const int* formalP)
	//{
	//	cout << "--- From print(const int*) --- \nArgument: " << *formalP << endl << endl;
	//}
}

namespace L171v2
{
	using namespace std;

	template<typename T1, typename T2>
	struct Pair
	{
		T1 first;
		T2 second;

		void toString() const
		{
			cout << "From Genreal Struct Template" << endl;
			cout << "First: " << first << endl;
			cout << "Second: " << second << endl << endl;
		}
	};

	//partial specialization
	template<typename T1>
	struct Pair<T1, int*>
	{
		T1 first;
		int* second;

		void toString() const
		{
			cout << "From Partially Specialized Struct Template" << endl;
			cout << "First: " << first << endl;
			cout << "Second: " << *second << endl << endl;
		}
	};

	//complete specialization
	template<>
	struct Pair<int*, int*>
	{
		int* first;
		int* second;

		void toString() const
		{
			cout << "From Completely Specialized Struct Template" << endl;
			cout << "First: " << *first << endl;
			cout << "Second: " << *second << endl << endl;
		}
	};

}

namespace L172
{
	using namespace std;
}

namespace L173
{
	using namespace std;
}

namespace L174
{
	using namespace std;
}

namespace L175
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
		//using std::pair;

		//pair<char, int> pair1{'H', 55};
		//pair<char, int> pair2{'B', 33};

		//std::cout << pair1.first << std::endl;
		//std::cout << pair1.second << std::endl;

		//pair1.swap(pair2);

		//std::cout << pair1.first << std::endl;
		//std::cout << pair1.second << std::endl;
	}


	// 165. Template Type Parameter Default Arguments and Non-Type Parameters
	{
		//using namespace L165;

		//float* ptr = nullptr;

		//ptr = instantiate<float>();

		//cout << *ptr << endl;

		//delete ptr;
	}

	{
		//using namespace L165v2;

		//float* ptr = nullptr;

		//ptr = instantiate<55, float>();

		//cout << *ptr << endl;

		//delete ptr;
	}

	{
		//using namespace L165v3;

		////ArrayEntity<int, 5> arrayEntity1;
		//ArrayEntity<> arrayEntity1;

		//arrayEntity1.m_Array[0] = 44;

		//arrayEntity1.toString();
	}

	{
		//using namespace L165v4;

		//ArrayEntity<> arrayEntity1;

		//arrayEntity1[0] = 44;

		////arrayEntity1.toString();

		//for (int i = 0; i < sizeof(arrayEntity1) / sizeof(int); i++)
		//{
		//	cout << arrayEntity1[i] << endl;
		//}
	}

	{
		//using namespace L165v5;

		//ArrayEntity<int, ESize::Two> arrayEntity1;

		//arrayEntity1[0] = 44;

		//for (int i = 0; i < ESize::Two; i++)
		//{
		//	cout << arrayEntity1[i] << endl;
		//}
	}

	{
		//using namespace L165v6;

		//EntityTemplate<entity> entityTemplate;

		//entityTemplate.toString();

	}


	// 166. Template Parameter Reuse
	{
		//using namespace L166;

		//Entity<int, &x> entity;

		//cout << entity.getVal() << endl;
	}

	{
		//using namespace L166v2;

		//static const int x = 53;

		//Entity<int, x> entity;

		//cout << entity.getVal() << endl;
	}

	{
		//using namespace L166v3;

		//Entity<int, &x, short> entity;

		//cout << entity.getVal() << endl;
	}


	// 167. Static Variables with Function and Class Templates
	{
		//using namespace L167;

		//increment();
		//increment();

		//increment<double>();
		//increment<double>();

		//increment<char>();
		//increment<char>();

		//
		//Entity<short> entity1;
		//entity1.increment();
		//entity1.increment();

		//Entity<char> entity2;
		//entity2.increment();
		//entity2.increment();
		//entity2.increment();
		//entity2.increment();
	}


	// 168. Define Class and Struct Templates in Header Files
	{
		//using namespace L168;

		////print<int>(55);

		////
		//Entity<int> entity1(55);

		//cout << entity1.getMember() << endl;
	}

	{
		//using namespace L168v2;

		//Entity<int> entity1(55);
		//Entity<float> entity2(55.4f);
		//Entity<short> entity3(55);
		//
		//cout << entity1.getMember() << endl;
		//cout << entity2.getMember() << endl;
		//cout << entity3.getMember() << endl;
	}


	// 169. Class or Struct Templates as Function Formal Parameters
	{
		//using namespace L169;

		//Pair<float> pair{33.66f, 44.32f};

		////cout << smallestMember(pair) << endl;
		//cout << smallestMember(&pair) << endl;
	}

	{
		//using namespace L169v2;

		//Pair<int> pair{33, 44};

		//cout << smallestMember(pair) << endl;

		//cout << addMembers(pair) << endl;
	}

	{
		//using namespace L169v3;

		//Pair<int> pair1{33, 44};
		//cout << pair1 << endl;

		//Pair<int> pair2{2, 3};
		//cout << pair2 << endl;

		//Pair<Pair<int>> pairOfPairs{ pair1, pair2 };

		//cout << addMembers(pairOfPairs) << endl;
	}


	// 170. Function Overloading with Function Templates
	{
		//using namespace L170;

		//const int x = 4;

		//print('H');
		//print(x);
		//print<int>(x);
		//print(&x);
		//print(55, 'R');
	}


	// 171. Template Specialization
	{
		//using namespace L171;

		//print<char>('H');

		//const int x = 44;
		//print(x);
		//print(&x);

		//int y = 22;
		//print<const int*>(&y);

		////
		//char myChar = 'H';
		//print(&myChar);
	}

	{
		using namespace L171v2;

		Pair<int, char> pair1{ 55, 'G' };
		pair1.toString();

		int x = 5;
		Pair<char, int*> pair2{'A', &x };
		pair2.toString();

		Pair<int*, int*> pair3{ &x, &x };
		pair3.toString();
	}










































	std::cout << "\nEND!\n";

	return 0;
}