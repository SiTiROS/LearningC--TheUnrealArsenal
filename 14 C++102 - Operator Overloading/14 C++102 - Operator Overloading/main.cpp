﻿#include <iostream>
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
	Entity(int memberP = 5) : member(memberP) {}

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
	// return Entity(member + other.member); // связка 1
	return add(other); // связка 2
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


	cout << endl;
	return 0;
}
