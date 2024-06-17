#include <iostream>
#include <utility>

using namespace std;

// struct Vector2D
// {
// 	float x{};
// 	float y{};
//
// 	Vector2D operator-() const;
// };
//
// Vector2D Vector2D::operator-() const
// {
// 	Vector2D temp;
// 	temp.x = -x;
// 	temp.y = -y;
//
// 	return temp;
// }

class Entity
{
public:
	Entity(int memberP = 5) : member(memberP)
	{
		cout << "Default Constructor Invoked." << endl;
	}

	Entity(const Entity& other)
		:member(other.member)
	{
		cout << "Copy Constructor Invoked." << endl;
	}

	bool operator==(const Entity& other) const;
	bool operator!=(const Entity& other) const;

	bool operator<(const Entity& other) const;

	Entity add(const Entity& other) const;
	Entity operator+(const Entity& other) const;

	Entity multiply(const Entity& other) const;
	Entity operator*(const Entity& other) const;

	Entity& operator++();
	Entity operator++(int);

	Entity& operator--();
	Entity operator--(int);

	void toString() const { cout << member << endl; }

	int getMember() const;

private:
	int member{ 1 };
};

bool Entity::operator==(const Entity& other) const
{
	return member == other.member;
}

bool Entity::operator!=(const Entity& other) const
{
	// return member != other.member;  //or
	// return !(operator==(other)); //or
	return !(*this == other); //or тут мы сравниваем объекты как бы через оператор == который внутри уже сравнивает bool Entity::operator==(const Entity& other){ const return member == other.member;}
}

bool Entity::operator<(const Entity& other) const
{
	return member < other.member;
}

Entity Entity::add(const Entity& other)	const
{
	Entity temp;
	temp.member = member + other.member;
	return temp; // связка 2
	// return *this + other; // связка 1
	// return operator+(other); // и так можно
}

Entity Entity::operator+(const Entity& other) const
{
	return Entity(member + other.member); // связка 1
	// return add(other); // связка 2
}

Entity Entity::multiply(const Entity& other) const
{
	return Entity(member * other.member);
}

Entity Entity::operator*(const Entity& other) const
{
	return Entity(member * other.member);
}

Entity& Entity::operator++()
{
	++member;
	return *this;
}

Entity Entity::operator++(int n)
{
	Entity temp = *this;
	if (n != 0)
	{
		//increment n times
		member += n;
	}
	else
	{
		++*this; // вызывается Entity& Entity::operator++()
		// ++member; // можно и так
	}
	return temp;
}

Entity& Entity::operator--()
{
	--member;
	return *this;
}

Entity Entity::operator--(int n)
{
	Entity temp = *this;
	if (n != 0)
	{
		member -= n;
	}
	else
	{
		--member;
	}
	return temp;
}

int Entity::getMember() const
{
	return member;
}

void toString(Entity entityP)
{
	cout << entityP.getMember() << endl;
}


class DoubleEntity
{
public:
	DoubleEntity(int member1P = 1, int member2P = 1)
		:member1(member1P), member2(member2P)
	{
	}

	bool operator==(const DoubleEntity& other) const
	{
		return ((member1 == other.member1) && (member2 == other.member2));
	}

private:
	int member1;
	int member2;
};


class Entity2
{
public:
	Entity2(int x = 1)
	{
		memberPtr = new int(x);
	}

	//Copy constructor
	Entity2(const Entity2& other)
		: memberPtr(other.memberPtr)
	{}

	~Entity2()
	{
		delete memberPtr;
	}

	int getMemberPtr() const
	{
		return *memberPtr;
	}

private:
	int* memberPtr;
};

//Note: Copy-by-value parameter
void toString(Entity2 entityP)
{
	cout << entityP.getMemberPtr() << endl;
}


class Entity3
{
public:
	Entity3(int x = 1)
	{
		memberPtr = new int(x);
	}

	//Deep Copy constructor
	Entity3(const Entity3& other)
		:Entity3(*other.memberPtr)
	{
		// memberPtr = new int;
		// *memberPtr = *other.memberPtr;
	}

	Entity3& operator=(const Entity3& other)
	{
		if (this != &other) //Avoid self-assignment
		{
			//*memberPtr = *other.memberPtr; // simple copy assignment

			delete memberPtr;
			memberPtr = new int;
			*memberPtr = *other.memberPtr;
		}
		return *this;
	}

	~Entity3()
	{
		delete memberPtr;
	}

	int getMemberPtr() const
	{
		return *memberPtr;
	}

private:
	int* memberPtr;
};

//Note: Copy-by-value parameter
void toString(Entity3 entityP)
{
	cout << entityP.getMemberPtr() << endl;
}


struct Vector2D
{
	Vector2D& operator=(const Vector2D& other)
	{
		x = other.x;
		y = other.y;

		return *this;
	}

	float x;
	float y;
};


class ArrayList
{
public:
	ArrayList(int lenghtP = 1)
	{
		length = lenghtP;
		list = new char[length];

		for (int i = 0; i < length; i++)
		{
			//list[i] = 'X';
			*(list + i) = 'X';
		}
	}

	~ArrayList()
	{
		delete[] list;
	}

	ArrayList& operator=(const ArrayList& other)
	{
		if (this != &other)
		{
			delete[] list;

			length = other.length;
			list = new char[length];

			for (int i = 0; i < length; i++)
			{
				// list[i] = 'X';
				*(list + i) = 'X';
			}
		}

		return *this;
	}

	void toString()
	{
		for (int i = 0; i < length; i++)
		{
			// cout << list[i];
			cout << *(list + i);
		}
		cout << endl;
	}

private:
	char* list;
	int length;
};


void test(const int& x)
{
	cout << &x << "\t" << x << "\tL-value Reference." << endl;
}

void test(int&& x)
{
	cout << &x << "\t" << x << "\tR-value Reference." << endl;
}


class MoveConstructor
{
public:
	MoveConstructor(int memberP = 1)
		:member(memberP)
	{
		cout << "Default Constructor Invoked." << endl;
	}

	MoveConstructor(const MoveConstructor& other)
		:member(other.member)
	{
		cout << "Copy Constructor Invoked." << endl;
	}

	MoveConstructor(const MoveConstructor&& other) noexcept
		:member(other.member)
	{
		cout << "Move Constructor Invoked." << endl;
	}

	MoveConstructor operator+(const MoveConstructor& other) const
	{
		// MoveConstructor temp(MoveConstructor(member + other.member));
		// MoveConstructor temp(member + other.member);
		// return move(temp); // вот так будет только работать не дефолтные конструкторы!
		return MoveConstructor(member + other.member);
	}

	void toString() const
	{
		cout << member << endl;
	}

private:
	int member;
};

class MoveConstructor2
{
public:
	MoveConstructor2(int x = 1)
	{
		memberPtr = new int(x);
	}

	//Deep Copy Constructor...
	MoveConstructor2(const MoveConstructor2& other)
		:MoveConstructor2(*other.memberPtr)
	{
		cout << "Copy Constructor Invoked." << endl;
	}

	//Move Constructor
	MoveConstructor2(MoveConstructor2&& other) noexcept
		:memberPtr(other.memberPtr)
	{
		other.memberPtr = nullptr;
		cout << "Move Constructor Invoked." << endl;
	}

	~MoveConstructor2()
	{
		if (memberPtr != nullptr)
		{
			delete memberPtr;
			cout << "Dynamic object deallocated." << endl;
		}
		else
		{
			cout << "Noting to deallocate." << endl;
		}
	}

	MoveConstructor2 operator+(const MoveConstructor2& other) const
	{
		MoveConstructor2 temp(*memberPtr + *other.memberPtr);
		return move(temp);
		//return temp;
	}

	//Copy Assignment Operator
	MoveConstructor2& operator=(const MoveConstructor2& other)
	{
		cout << "Copy Assignment Invoked." << endl;
		if (this != &other)
		{
			delete memberPtr;
			memberPtr = new int;
			*memberPtr = *other.memberPtr;
		}

		return *this;
	}

	//Move Assignment Operator
	MoveConstructor2& operator=(MoveConstructor2&& other) noexcept
	{
		cout << "Move Assignment Invoked." << endl;
		if (this != &other)
		{
			delete memberPtr;

			//reallocate resources to *this
			memberPtr = other.memberPtr;
			other.memberPtr = nullptr;
		}

		return *this;
	}

	MoveConstructor2& operator++() // это префиксный инкремент. Он увеличивает значение переменной memberPtr на 1, и затем возвращает новое значение объекта 
	{
		++*memberPtr;
		return *this;
	}

	MoveConstructor2 operator++(int) // это постфиксный инкремент. Он увеличивает значение переменной memberPtr на 1, но сначала возвращает старое значение объекта 
	{
		MoveConstructor2 temp = *this;
		++*memberPtr;

		return move(temp);
	}

	void toString() const
	{
		cout << *memberPtr << endl;
	}

private:
	int* memberPtr;
};


class EntityFriend
{
	friend void toString(EntityFriend entityP);

public:
	EntityFriend(int memberP = 1)
		:member(memberP)
	{
	}

	EntityFriend(const EntityFriend& other)
		:member(other.member)
	{
		cout << "Copy Constructor Invoked." << endl;
	}

private:
	int member;
};

void toString(EntityFriend entityP) //friend
{
	cout << entityP.member << endl;
}


class B;

class A
{
public:
	void toString(const B& b) const;
	void func(B& b);
};

class B
{
	// friend void A::toString(const B& b) const;
	friend class A;

private:
	int member{ 5 };
	void toString() const { cout << member << endl; }
};

void A::toString(const B& b) const
{
	cout << b.member << endl;
	b.toString();
}

void A::func(B& b)
{
	//cout << b.member << endl;
}


struct SVector2D
{
	float x{};
	float y{};

	// SVector2D operator-() const
	// {
	// 	SVector2D temp;
	// 	temp.x = -x;
	// 	temp.y = -y;
	//
	// 	return temp;
	// }
};

SVector2D operator-(const SVector2D& operand)
{
	SVector2D temp;
	temp.x = -operand.x;
	temp.y = -operand.y;

	return temp;
}


class NEntity
{
	friend NEntity operator+(const NEntity& lho, const NEntity& rho);

public:
	NEntity(int memberP = 1)
		:member(memberP)
	{
	}

	// NEntity operator+(const NEntity& other) const
	// {
	// 	return NEntity(member + other.member);
	// }

	void toString() const
	{
		cout << member << endl;
	}

private:
	int member;
};

NEntity operator+(const NEntity& lho, const NEntity& rho)
{
	return NEntity(lho.member + rho.member);
}


class OEntity
{
	friend ostream& operator<<(ostream& output, const OEntity& entityP);
	friend istream& operator>>(istream& input, OEntity& entity);

public:
	OEntity(int memberP = 1)
		:member(memberP)
	{
	}

	void toString() const
	{
		cout << member << endl;
	}

private:
	int member;
};

ostream& operator<<(ostream& output, const OEntity& entityP)
{
	output << entityP.member << endl;
	return output;
}

istream& operator>>(istream& input, OEntity& entityP)
{
	input >> entityP.member;
	return input;
}


struct CVector3D
{
	CVector3D()
		:x(0.0f), y(0.0f), z(0.0f)
	{
	}

	CVector3D(float xP, float yP, float zP)
		:x(xP), y(yP), z(zP)
	{
	}

	float x;
	float y;
	float z;
};

struct CVector2D
{
	CVector2D()
		:x(0.0f), y(0.0f)
	{
	}

	//conversation constructor
	CVector2D(const CVector3D& vec3P)
	{
		x = vec3P.x;
		y = vec3P.y;
	}

	float x;
	float y;
};

struct C2Vector2D
{
	C2Vector2D() : x(0.0f), y(0.0f) {}

	explicit C2Vector2D(float inF)
		: x(inF), y(inF)
	{
		cout << "Conversion Constructor Invoked!" << endl;
	}

	// C2Vector2D operator+(const C2Vector2D& rho)
	// {
	// 	C2Vector2D temp;
	// 	temp.x = x + rho.x;
	// 	temp.y = y + rho.y;
	// 	return temp;
	// }

	float x;
	float y;
};

C2Vector2D operator+(const C2Vector2D& lho, const C2Vector2D& rho)
{
	C2Vector2D temp;
	temp.x = lho.x + rho.x;
	temp.y = lho.y + rho.y;
	return temp;
}

class CEntity
{
public:
	CEntity(int memberP = 1) :member(memberP) {}

	explicit operator int() const
	{
		return member;
	}

private:
	int member;
};

struct CNVector3D
{
	CNVector3D() : x(0.0f), y(0.0f), z(0.0f) {}

	CNVector3D(float xP, float yP, float zP)
		: x(xP), y(yP), z(zP) {}

	float x;
	float y;
	float z;
};

struct CNVector2D
{
	CNVector2D(float inF = 0.0f) : x(inF), y(inF) {}

	//conversation constructor
	// CNVector2D(const CNVector3D& vec3P)
	// {
	// 	x = vec3P.x;
	// 	y = vec3P.y;
	// }

	//conversation operation/function
	operator CNVector3D() const
	{
		cout << "Conversation Function Invoked!" << endl;
		return CNVector3D(x, y, 0);
	}

	float x;
	float y;
};

struct Vector3D2
{
	Vector3D2() : x(0.0f), y(0.0f), z(0.0f) {}

	Vector3D2(float xP, float yP, float zP)
		: x(xP), y(yP), z(zP) {}

	float x;
	float y;
	float z;
};

struct Vector2D2
{
	Vector2D2(float inF = 0.0f) : x(inF), y(inF) {}

	Vector2D2& operator=(const Vector3D2& rho)
	{
		x = rho.x;
		y = rho.y;
		return *this;
	}

	float x;
	float y;
};


int main()
{
	// Vector2D vec1, vec2{ 15.0f, 5.0f };
	// cout << vec1.x << " " << vec1.y << endl;
	// cout << vec2.x << " " << vec2.y << endl;
	//
	// cout.operator<<(vec2.y);
	// int x{}, y{ 5 };
	// x = -y;
	// cout << x << endl;
	// cout << y << endl;
	//
	// Vector2D vec1, vec2{ 15.0f, 5.0f };
	//
	// vec1 = -vec2;
	// cout << vec1.x << endl;
	// cout << vec2.y << endl;


	// // int x{ 1 }, y{ 5 };
	// // x++ += 5; // не будет работать так
	//
	// Entity entity1;
	//
	// // cout << (++entity1).getMember() << endl;
	// // cout << entity1.getMember() << endl;
	//
	// //entity1++;  
	// //cout << entity1.getMember() << endl;
	//
	// entity1.operator++(1);
	// cout << entity1.getMember() << endl;
	//
	// --entity1;  
	// //entity1.operator--();
	// cout << entity1.getMember() << endl;


	// Entity entity1(3), entity2(3), result;
	// //result = entity1.add(entity2);
	// //result = entity1 * entity2;
	//
	// result = entity1.add(entity2.multiply(entity1));
	// //result = entity1 + entity2 * entity1;
	//
	// result.toString();


	// Entity entity1(2), entity2(3);
	// cout << (entity1 == entity2);
	// cout << (entity1 != entity2);
	// cout << (entity1 < entity2);
	//
	// DoubleEntity doubleEntity1(2, 2), doubleEntity2(2, 2);
	// cout << (doubleEntity1 == doubleEntity2);


	// Entity entity1(3), entity2(3);
	// Entity result = entity1;
	// result = entity1 + entity2;
	// toString(result);
	//
	// int* sourcePtr = new int(3);
	// int* copyPtr = sourcePtr;
	// cout << *sourcePtr << endl;
	// cout << *copyPtr << endl;
	// delete copyPtr;
	// sourcePtr = nullptr;
	// delete sourcePtr; // crash! если не вызывать sourcePtr = nullptr;
	//
	// int *sourcePtr = new int(3);
	// int *copyPtr = new int;
	// *copyPtr = *sourcePtr;
	// cout << *sourcePtr << endl;
	// cout << *copyPtr << endl;
	// delete copyPtr;
	// delete sourcePtr;
	//
	//Entity2 entity1(5);
	// {
	// 	Entity2 entity2(entity1);
	// }
	//cout << entity1.getMemberPtr() << endl;
	//toString(entity1);
	//
	// Entity3 entity3;
	// toString(entity3);
	// {
	// 	Entity3 entity4(entity3);
	// }


	// int x{ 2 }, y{ 7 }, z{ 3 };
	// x = y = z;
	// cout << x << '\t' << y << '\t' << z << '\t' << endl;
	//
	// Vector2D vec1{}, vec2{ 3, 5 }, vec3{ 12, 12 };
	// cout << vec1.x << '\t' << vec1.y << endl;
	//
	// // vec1.operator=(vec2); equal vec1 = vec2;
	// vec1 = vec2;
	// cout << vec1.x << '\t' << vec1.y << endl;
	//
	// vec1 = vec2 = vec3;
	// cout << "\nChained Assignment..." << endl;
	// cout << vec1.x << '\t' << vec1.y << endl;
	// cout << vec2.x << '\t' << vec2.y << endl;
	//
	// Entity3 entity1(5), entity2(7);
	// //Entity3 entity3 = entity1; // equal Entity3 entity3(entity1);
	// Entity3 entity3(entity1);
	// toString(entity3);
	// entity3 = entity2;
	// toString(entity3);
	//
	// ArrayList arrayList1(2), arrayList2(5), arrayList3;
	// arrayList1.toString();
	//
	// arrayList3 = arrayList1 = arrayList2;
	// arrayList1.toString();
	// arrayList3.toString();


	// int myInt{};
	// test((int&&)myInt); cast to int&& R-value
	// int &&myInt = 55 + 55;
	// test(myInt);
	// test((int&&)myInt);


	// MoveConstructor entity1(3), entity2(3);
	// MoveConstructor entity3(entity1 + entity2);
	// entity3.toString();
	//
	// MoveConstructor2 entity1(3), entity2(3);
	// MoveConstructor2 entity3(entity1 + entity2);
	// entity3.toString();


	// MoveConstructor2 entity1(5);
	// entity1 = MoveConstructor2(55);
	// entity1.toString();
	//
	// MoveConstructor2 entity1(5), entity2(1);
	// // entity1 = ++entity2;
	// entity1 = entity2++;
	// entity1.toString();
	// entity2.toString();


	// EntityFriend entity1(3);
	// toString(entity1);
	//
	// A a;
	// B b;
	// a.toString(b);


	// SVector2D vec1, vec2{ 15.0f, 5.0f };
	// vec1 = -vec2;
	// cout << vec1.x << " " << vec1.y << endl;
	// cout << vec2.x << " " << vec2.y << endl;
	//
	// NEntity entity1(3), entity2(12), result;
	// result = entity1 + entity2;
	// result.toString();


	// int x = 5;
	// cin >> x;
	// cout << x << endl;
	// cout.operator<<(x);
	//
	// OEntity entity1;
	// cin >> entity1;
	// cout << entity1;


	// CVector3D vec3(3, 5, 7);
	// CVector2D vec2(vec3);
	// cout << vec2.x << endl;
	// cout << vec2.y << endl;

	// // C2Vector2D vec(5.0f);
	// // C2Vector2D vec = C2Vector2D(5.0f);
	// // C2Vector2D vec = C2Vector2D(5);
	// C2Vector2D vec(5);
	//
	// vec = C2Vector2D(3.0f) + vec;
	// //vec = vec + 3.0f;
	//
	// cout << vec.x << endl;
	// cout << vec.y << endl;

	// CEntity entity1(55);
	// int x = (int)entity1;
	// // cout << "Entity 1 member: " << (int)entity1 << endl;
	// cout << "Entity 1 member: " << x << endl;

	// CNVector3D vec3(3, 4, 6);
	// CNVector2D vec2(4.4f);
	// vec3 = vec2;
	// cout << vec3.x << endl;
	// cout << vec3.y << endl;
	// cout << vec3.z << endl;

	// Vector3D2 vec3(3.0f, 5.0f, 7.0f);
	// Vector2D2 vec2(5.5f);
	// vec2 = vec3;
	// cout << vec2.x << endl;
	// cout << vec2.y << endl;




	cout << "___END___" << endl;
	cout << endl;
	return 0;
}