// 185. Capturing the this Pointer

#include <iostream>
using namespace std;

class Entity
{
public:
	Entity(int memberP = 0)
		: member(memberP)
	{
		cout << "Entity Constructor Invoked. Member is: " << member << endl;
	}

	~Entity()
	{
		cout << "Entity Destructor Invoked. Member was: " << member << endl;
	}

	void toString()
	{
		//[this]() {cout << "From Entity::toString: " << member << endl; }();
		//[=]() {cout << "From Entity::toString: " << member << endl; }(); // можно захват всего по значению но лучше this
		auto func = [this]() {cout << "From Entity::toString: " << member << endl; };
		func();
	}

	void setMember(int memberP)
	{
		member = memberP;
		//this->member = memberP; // можно и так this тут по умолчанию как бы скрыт
	}

private:
	int member;
};

int main()
{
	Entity entity1{ 55 };
	entity1.toString();

#if 0
#endif
	std::cout << "END" << std::endl;
	return 0;
}