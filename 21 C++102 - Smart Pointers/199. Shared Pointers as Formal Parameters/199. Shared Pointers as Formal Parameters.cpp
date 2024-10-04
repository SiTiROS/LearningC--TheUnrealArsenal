// 199. Shared Pointers as Formal Parameters

#include <iostream>
#include <memory>

class Entity
{
public:
	Entity(int memberP = 0) { member = memberP; }
	~Entity() { std::cout << "Entity Destuctor Invoked. Memory was: " << member << std::endl; }
	void toString()const { std::cout << member << std::endl; }
	void setMember(int memberP) { member = memberP; }

private:
	int member;
};

void display(std::shared_ptr<Entity> sPtrP)
{
	if (sPtrP == nullptr)
	{
		std::cout << "nullptr" << std::endl;
	}
	else
	{
		sPtrP->toString();
		std::cout << "display(): sPtrP use_count: " << sPtrP.use_count() << std::endl;
	}
}

void displayLnk(std::shared_ptr<Entity>& sPtrP)
{
	if (sPtrP == nullptr)
	{
		std::cout << "nullptr" << std::endl;
	}
	else
	{
		sPtrP->toString();
		std::cout << "display(): sPtrP use_count: " << sPtrP.use_count() << std::endl;
	}
}


int main()
{
#if 0
	auto sPtr1 = std::make_shared<Entity>(55);
	std::cout << "sPtr1 use_count:" << sPtr1.use_count() << std::endl;

	display(sPtr1);
	std::cout << "sPtr1 use_count:" << sPtr1.use_count() << std::endl;
#endif

#if 0
	auto sPtr1 = std::make_shared<Entity>(55);
	std::cout << "sPtr1 use_count:" << sPtr1.use_count() << std::endl;

	displayLnk(sPtr1);
	std::cout << "sPtr1 use_count:" << sPtr1.use_count() << std::endl;
#endif

#if 1
	auto sPtr1 = std::make_shared<Entity>(55);
	std::cout << "sPtr1 use_count:" << sPtr1.use_count() << std::endl;

	display(move(sPtr1));
	std::cout << "sPtr1 use_count:" << sPtr1.use_count() << std::endl;
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}