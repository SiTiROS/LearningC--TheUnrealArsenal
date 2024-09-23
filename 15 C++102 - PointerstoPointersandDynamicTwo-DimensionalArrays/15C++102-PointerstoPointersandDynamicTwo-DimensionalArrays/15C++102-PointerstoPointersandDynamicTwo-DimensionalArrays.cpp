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

	void toString() const { cout << '\t' << member; }
	void setMember(int memberP) { member = memberP; }

private:
	int member;
};


Entity** entityArrayFactory(int rowsP, int columnsP)
{
	Entity** pp_Table = new Entity * [rowsP];

	for (int i = 0; i < rowsP; i++)
	{
		pp_Table[i] = new Entity[columnsP];
	}

	return pp_Table;
}

void initialize(Entity** p, int rowsP, int columnsP)
{
	int temp{};

	for (int i = 0; i < rowsP; i++)
	{
		cout << "\nEnter " << columnsP << " numbers for row number: " << i << ": ";
		for (int j = 0; j < columnsP; j++)
		{
			temp = 0;
			cin >> temp;
			p[i][j].setMember(temp);
		}
	}
	cout << endl;
}

void print(Entity** p, int rowsP, int columnsP)
{
	cout << "\t----\tTable\t----" << endl;
	for (int i = 0; i < rowsP; i++)
	{
		for (int j = 0; j < columnsP; j++)
		{
			p[i][j].toString();
		}
		cout << endl;
	}
}

void deallocate(Entity** p, int rowsP)
{
	for (int i = 0; i < rowsP; i++)
	{
		delete[] p[i];
		p[i] = nullptr;
	}
	delete[] p;
}


// function to assign new address to pointer
// passing a pointer by value
// void modifyPointer(int* ptrP, int* addressToAssign)
// {
// 	ptrP = addressToAssign;
// }

// function to assign new address to pointer
// passing a pointer to a pointer
void modifyPointer(int** ptrP, int* addressToAssign)
{
	*ptrP = addressToAssign;
}

// function to assign new address to pointer
// passing to a reference to a pointer
void modifyPointer(int*& ptrP, int* addressToAssign)
{
	ptrP = addressToAssign;
}

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

	// массив в куче и указатель на него в стеке
	// const int SIZE = 3;
	// Entity* arrayPtr = new Entity[SIZE]{ Entity(3), Entity(5), Entity(9) };
	//
	// for (int i = 0; i < SIZE; i++)
	// {
	// 	arrayPtr[i].toString();
	// }
	//
	// delete[] arrayPtr;
	// arrayPtr = nullptr;


	// const int ARRAY_SIZE = 3;
	// int x{ 3 }, y{ 5 }, z{ 9 };
	//
	// int* pointerArray[ARRAY_SIZE]{ &x, &y, &z };
	//
	// for (int i = 0; i < ARRAY_SIZE; i++)
	// {
	// 	cout << *pointerArray[i] << '\t';
	// }


	// массив указателей в стеке которые создают объекты в куче
	// const int SIZE = 3;
	// Entity* pointerArray[SIZE]{};
	//
	// cout << "--- Allocation ---" << endl;
	// for (int i = 0; i < SIZE; i++)
	// {
	// 	pointerArray[i] = new Entity(i);
	// }
	//
	// cout << "\n--- Entity::toString() followed by Deallocation ---" << endl;
	// for (int i = 0; i < SIZE; i++)
	// {
	// 	pointerArray[i]->toString();
	// 	delete pointerArray[i];
	// 	pointerArray[i] = nullptr;
	// }


	// массив указателей в стеке которые создают массивы в куче
	// const int ARRAY_SIZE = 2;
	//
	// Entity* pointerArray[ARRAY_SIZE]{};
	//
	// pointerArray[0] = new Entity[2]{ Entity(3), Entity(5) };
	// pointerArray[1] = new Entity[3]{ };
	//
	// pointerArray[1][2].setMember(55);
	//
	// for (int i = 0; i < ARRAY_SIZE; i++)
	// {
	// 	delete[] pointerArray[i];
	// 	pointerArray[i] = nullptr;
	// }


	//динамичесские двухсвязанные массивы
	// const int ROWS = 2;
	// const int COLUMNS = 3;
	//
	// Entity** pp_Table = new Entity* [ROWS]{};
	//
	// for (int currentRow = 0; currentRow < ROWS; currentRow++)
	// {
	// 	pp_Table[currentRow] = new Entity[COLUMNS]{};
	// }
	//
	// for (int i = 0; i < ROWS; i++)
	// {
	// 	for (int j = 0; j < COLUMNS; j++)
	// 	{
	// 		pp_Table[i][j].setMember(10 + i + j);
	// 	}
	// }
	//
	// for (int i = 0; i < ROWS; i++)
	// {
	// 	for (int j = 0; j < COLUMNS; j++)
	// 	{
	// 		pp_Table[i][j].toString();
	// 	}
	// }
	//
	// for (int i = 0; i < ROWS; i++)
	// {
	// 	delete[] pp_Table[i];
	// 	pp_Table[i] = nullptr;
	// }
	// delete[] pp_Table;



	//140. Dynamic Two-Dimensional Arrays Exercise

	// int rows{}, columns{};
	//
	// cout << "Enter the number of rows and columns: ";
	// cin >> rows >> columns;
	//
	// Entity** pp_Table = entityArrayFactory(rows, columns);
	//
	// initialize(pp_Table, rows, columns);
	//
	// print(pp_Table, rows, columns);
	//
	// deallocate(pp_Table, rows);



	// 141. References to Pointers

	int var{ 55 }, varToAssign{ 250 };
	int* ptr = &var;

	cout << "Before:\t " << *ptr << endl;

	// Reference to Pointer
	// refToPtr is an Alias of ptr 
	// int*& refToPtr = ptr;
	// refToPtr = &varToAssign;
	// *refToPtr = 45;

	modifyPointer(ptr, &varToAssign); // passing to a reference to a pointer
	//modifyPointer(&ptr, &varToAssign); // passing a pointer to a pointer

	cout << "After:\t " << *ptr << endl;



	cout << "\nEND" << endl;
	return 0;
}