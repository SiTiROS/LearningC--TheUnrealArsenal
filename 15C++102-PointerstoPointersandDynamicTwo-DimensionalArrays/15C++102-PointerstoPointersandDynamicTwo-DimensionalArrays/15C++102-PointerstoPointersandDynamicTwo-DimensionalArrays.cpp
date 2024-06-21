#include <iostream>

using namespace std;

int main()
{
	int var = 55;
	int* ptr = &var; // указатель на переменную, нужно выполнить операцию взятия адреса &
	*ptr = 0; // разыменование указателя для изменения значения по указателю

	cout << "Variable:" << endl;
	cout << &var << '\t' << var << endl; // адресс и значение переменной

	cout << "\nPointer to Variable:" << endl;
	*ptr = 1;
	cout << &ptr << '\t' << ptr << '\t' << *ptr << endl; // адресс указателя, адресс переменной на которую записан указатель и значение переменной чтобы его получить надо разыменовать указатель *

	cout << "\nPointer to Pointer to Variable:" << endl;
	int** ptrToPtr = &ptr; // указатель на указатель
	**ptrToPtr = 2;
	cout << &ptrToPtr << '\t' << ptrToPtr << '\t' << *ptrToPtr << '\t' << **ptrToPtr << endl; // адресс указателя на указатель, адресс указателя на который записан указатель, разыменование адреса на указатель(*), значение переменной(**)

	cout << "\nPointer to Pointer to Pointer to Variable:" << endl;
	int*** ptrToPtrToPtr = &ptrToPtr; // указатель на указатель на указатель
	***ptrToPtrToPtr = 3;
	cout << &ptrToPtrToPtr << '\t' << ptrToPtrToPtr << '\t' << *ptrToPtrToPtr << '\t' << **ptrToPtrToPtr << '\t' << ***ptrToPtrToPtr << endl;






	cout << "END" << endl;
	return 0;
}