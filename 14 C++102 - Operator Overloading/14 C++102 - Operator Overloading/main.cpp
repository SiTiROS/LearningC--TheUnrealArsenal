#include <iostream>
using namespace std;

struct Vector2D
{
	float x{};
	float y{};

	Vector2D operator-() const;
};

Vector2D Vector2D::operator-() const
{
	Vector2D temp;
	temp.x = -x;
	temp.y = -y;

	return temp;
}

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


	cout << endl;
	return 0;
}