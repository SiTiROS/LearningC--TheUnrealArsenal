#include <iostream>

using namespace std;

class Entity
{
public:
	Entity(int memberP = 0) : member(memberP)
	{
		cout << "Entity Constructor Invoked. Member is: " << member << endl;
	}

	~Entity() { cout << "Entity Destructor Invoked. Member was: " << member << endl; }

	void toString() const { cout << member << endl; }
	void setMember(int memberP) { member = memberP; }

private:
	int member;
};

int main()
{
	//137. Pointers to Pointers
	// int var = 55;
	// int* ptr = &var; // указатель на переменную, нужно выполнить операцию взятия адреса &
	// *ptr = 0; // разыменование указателя для изменения значения по указателю
	//
	// cout << "Variable:" << endl;
	// cout << &var << '\t' << var << endl; // адресс и значение переменной
	//
	// cout << "\nPointer to Variable:" << endl;
	// *ptr = 1;
	// cout << &ptr << '\t' << ptr << '\t' << *ptr << endl; // адресс указателя, адресс переменной на которую записан указатель и значение переменной чтобы его получить надо разыменовать указатель *
	//
	// cout << "\nPointer to Pointer to Variable:" << endl;
	// int** ptrToPtr = &ptr; // указатель на указатель
	// **ptrToPtr = 2;
	// cout << &ptrToPtr << '\t' << ptrToPtr << '\t' << *ptrToPtr << '\t' << **ptrToPtr << endl; // адресс указателя на указатель, адресс указателя на который записан указатель, разыменование адреса на указатель(*), значение переменной(**)
	//
	// cout << "\nPointer to Pointer to Pointer to Variable:" << endl;
	// int*** ptrToPtrToPtr = &ptrToPtr; // указатель на указатель на указатель
	// ***ptrToPtrToPtr = 3;
	// cout << &ptrToPtrToPtr << '\t' << ptrToPtrToPtr << '\t' << *ptrToPtrToPtr << '\t' << **ptrToPtrToPtr << '\t' << ***ptrToPtrToPtr << endl;



	//138. Arrays of Pointers
	// const int ARRAY_SIZE = 3;
	// int x{ 3 }, y{ 5 }, z{ 9 };
	//
	// int* pointerArray[ARRAY_SIZE]{ &x, &y, &z };
	// *pointerArray[0] = 333;
	//
	// cout << "x: " << &x << '\t';
	// cout << "y: " << &y << '\t';
	// cout << "z: " << &z << '\t';
	// cout << endl << endl;
	//
	// for (int i = 0; i < ARRAY_SIZE; i++)
	// {
	// 	cout << &pointerArray[i] << '\t'; // адресс самого указателя элемента массива
	// 	cout << pointerArray[i] << '\t'; // адресс переменной на которую указывает указатель
	// 	cout << *pointerArray[i] << '\t'; // значение переменной на которую указатель указывает
	// 	cout << endl;
	// }


	// const int ARRAY_SIZE = 3;
	//
	// Entity entity1, entity2{ 5 };
	//
	// // Entity* pointerArray[ARRAY_SIZE]{ &entity1, &entity2 };
	// Entity* pointerArray[ARRAY_SIZE] = { &entity1, &entity2, nullptr };
	//
	// pointerArray[0]->setMember(250);
	// pointerArray[0]->toString();
	// pointerArray[1]->toString();
	//
	// if (pointerArray[2] == nullptr)
	// {
	// 	cout << "nullptr" << endl;
	// }



	//139. Dynamic Two-Dimensional Arrays

	cout << "\nEND" << endl;
	return 0;
}