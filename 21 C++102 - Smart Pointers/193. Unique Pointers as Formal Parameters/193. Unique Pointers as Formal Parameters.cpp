// 193. Unique Pointers as Formal Parameters

#include <iostream>
#include <memory>

using namespace std;

class Entity
{
public:
	Entity(int memberP = 44) { member = memberP; }
	~Entity() { std::cout << "Entity Destructor invoked." << std::endl; }
	void toString() const { std::cout << member << std::endl; };
	void setMember(int memberP) { member = memberP; };

private:
	int member;
};

void print(unique_ptr<Entity> uPtrP)
{
	if (uPtrP != nullptr)
		uPtrP->toString();
	else
		cout << "nullptr" << endl;
}

void printLnk(const unique_ptr<Entity>& uPtrP) //ссылка
{
	//uPtrP.reset(); //так нельзя
	//uPtrP->setMember(4); //так можно

	if (uPtrP != nullptr)
		uPtrP->toString();
	else
		cout << "nullptr" << endl;
} //деструктор вызван не будет

void printLnkRValue(unique_ptr<Entity>&& uPtrP) //ссылка на Rvalue
{
	if (uPtrP != nullptr)
		uPtrP->toString();
	else
		cout << "nullptr" << endl;
} //деструктор вызван не будет


int main()
{
#if 0
	unique_ptr<Entity> uEntityPtr = make_unique<Entity>(1);

	uPtrRef->toString();

	print(move(uEntityPtr));

	if (uEntityPtr == nullptr)
		cout << "uEntityPtr == nullptr" << endl;
#endif

#if 0
	unique_ptr<Entity> uEntityPtr = make_unique<Entity>(1);

	unique_ptr<Entity>& uPtrRef = uEntityPtr; // ссылка на уникальный указатель

	uPtrRef->toString();

	print(move(uPtrRef));
#endif

#if 0
	unique_ptr<Entity> uEntityPtr = make_unique<Entity>(1);

	printLnk(uEntityPtr);

	if (uEntityPtr == nullptr)
		cout << "uEntityPtr == nullptr" << endl;
#endif

#if 0
	printLnkRValue(std::make_unique<Entity>(12324));
#endif

#if 1
	unique_ptr<Entity> up_Entity = make_unique<Entity>(1);

	printLnkRValue(static_cast<unique_ptr<Entity>&&>(up_Entity));

	printLnkRValue(std::move(up_Entity));

	//printLnk(std::move(up_Entity));

#endif




#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}