#include <iostream>
#include <algorithm>

using namespace std;


int binarySearch(int array[], int size, int item)
{
	int low = 0;         // low index
	int high = size - 1; // high index

	while (low <= high)
	{
		int mid = (low + high) / 2; // mid index
		int guess = array[mid];     // value of mid index

		if (guess == item)
		{
			return mid; // value of mid index
		}

		if (guess < item)
		{
			low = mid + 1;
			cout << low << endl;
		}
		else
		{
			high = mid - 1;
			cout << mid << endl;
		}
	}

	return -1;
}


void selectionSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}
}

//void selectionSort2()
//{
//	int n = 7;
//	int arr[7]{ 34, 12, 12, 1, 3, 5, 66 };
//
//	for (int i = 0; i < n - 1; i++)
//	{
//		int minIndex = i;
//		for (int j = i + 1; j < n; j++)
//		{
//			if (arr[j] < arr[minIndex])
//			{
//				minIndex = j;
//			}
//		}
//		swap(arr[i], arr[minIndex]);
//	}
//
//	for (int i = 0; i < n; i++) 
//	{
//		cout << arr[i] << " ";
//	}
//}




// Уебанское создание, заполнение и вывод 2D массива - пробема с  выводом через указатель
//const int M_MAXIMAL = 100;
//void print_array2d(int A[][M_MAXIMAL], int N, int M)
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			cout << A[i][j] << '\t';
//			cout << &A[i][j] << "   ";
//		}
//		cout << '\n';
//	}
//}


// Нормальное создаение и вывод 2D массива через указатель
void print_array2d(int* p, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << p[i * M + j] << '\t'; // это равносильно A[i][j] если бы без указателя
		}
		cout << '\n';
	}
}



// Практика указателей
int f(int* x)
{
	//return *x = *x * 2;
	return *x *= 2;
}

void arrayArguments(int* ar, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << *(ar + i) << ' ';
	}
	cout << endl;
}

void arrayFunc(int* ar, int len)
{
	for (int* ptr = ar; ptr < ar + len; ptr++)
	{
		cout << *ptr << ' ' << endl;
		//cout << *(ar + len -1) << ' ' << endl;//смотрю условия -адрес массива + ссдвиг длины - 1 так как с 0 начало
	}
	cout;
}


//Пузырьковая сортировка
bool cmp(int** x, int** y)
{
	return **x < **y;
}

void sort(int* ar, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int itterator = 0;
		for (int* j = ar; j < ar + len - 1; j++)
		{
			itterator++;
			cout << "i: " << i << "   itterator: " << itterator << endl;
			cout << "*j: " << *j << endl;
			int* k = j + 1;
			if (cmp(&k, &j))
			{
				int tmp = *j;
				*j = *k;
				*k = tmp;
			}
			cout << endl;
			for (int i = 0; i < 10; i++)
			{
				cout << ar[i] << ' ';
			}
			cout << endl;
		}
	}
}

// связанный список
class link
{
public:
	int val;
	link* next;
};

class linkList
{
private:
	link* first;
	link* last;

public:
	linkList() : first(nullptr), last(nullptr) {}

	bool isEmpty() { return first == nullptr; }

	void pushFront(int x)
	{
		link* tmp = new link;
		tmp->val = x;
		tmp->next = first;
		first = tmp;
		//if(last==nullptr)
		//{
		//	last = first;
		//}
	}

	void pushBack(int x)
	{
		link* tmp = new link;
		tmp->val = x;
		tmp->next = nullptr;
		if (this->isEmpty())
		{
			first = last = tmp;
		}
		else
		{
			last->next = tmp;
			last = tmp;
		}
	}

	void popFront()
	{
		link* tmp = first->next;
		delete first;
		first = tmp;
	}

	void popBack()
	{
		link* tmp = first;
		while (tmp->next != last)
		{
			tmp = tmp->next;
		}
		delete last;
		last = tmp;
		last->next = nullptr;
	}

	void display()
	{
		link* tmp = first;
		while (tmp != nullptr)
		{
			cout << tmp->val << endl;
			tmp = tmp->next;
		}
	}
};

//указатель на функцию ???
void test() { cout << "Test" << endl; }
void test2() { cout << "Test2" << endl; }

//
void add(int x, int y)
{
	cout << "x + y = " << x + y << endl;
}

void substract(int x, int y)
{
	cout << "x - y = " << x - y << endl;
}

void multiply(int x, int y)
{
	cout << "x * y = " << x * y << endl;
}

//
void select(void(*op)(int, int), int x, int y)
{
	op(x, y);
}

//
bool cmp2(int x, int y)
{
	return x < y;
}

//
int add2(int x, int y)
{
	return x + y;
}

int substract2(int x, int y)
{
	return x - y;
}

int multiply2(int x, int y)
{
	return x * y;
}

int (*select(int choice))(int x, int y)
{
	switch (choice)
	{
	case 2:
		return substract2;
	case 3:
		return multiply2;
	default:
		return add2;
	}
}

int main()
{
	//указатель на функцию ???
	void (*ptr)();
	ptr = test;
	ptr();
	ptr = test2;
	ptr();

	//
	int a = 10;
	int b = 5;
	void (*operations[3])(int, int) = { add, substract, multiply };

	for (unsigned i = 0; i < size(operations); i++)
	{
		operations[i](a, b);
	}

	//
	select(add, a, b);

	//
	int ar[] = { 4, 3, 5, 7, 1, -12, 5, 15, -15 };
	sort(ar, ar + size(ar), cmp2);
	for (int i = 0; i < size(ar); i++)
	{
		cout << ar[i] << " ";
	}
	cout << endl;

	//
	int(*action)(int, int) = select(1);
	cout << action(8, 5) << endl;

	action = select(2);
	cout << action(8, 5) << endl;

	action = select(3);
	cout << action(8, 5) << endl;

	//список - но надо переделать и улучшить - дз
	linkList test;
	test.pushBack(10);
	test.pushBack(20);
	test.pushFront(30);
	test.popBack();
	test.popBack();
	test.popFront();
	test.display();



	//Пузырьковая сортировка
	////int ar[] = { 4, -5, 8, -1, 0, 15, 3, -7, 9, 11 };
	//int ar[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	//
	//sort(ar, size(ar));
	//
	//cout << size(ar) << endl;
	//
	//for (int i = 0; i < size(ar); i++)
	//{
	//	cout << ar[i] << ' ';
	//}

	// practices pointers
	//int x = 5;
	//cout << f(&x) << endl;
	//
	//int array[] = { 1, 2, 3, 4, 5 };
	//for (int i = 0; i < size(array); i++)
	//{
	//	cout << (array + i) << ' ';
	//	cout << *(array + i) << ' ';
	//	cout << endl;
	//}
	//
	//int array[] = { 1, 2, 3, 4, 5 };
	//arrayArguments(&array[0], size(array));
	//arrayArguments(array, size(array));
	//
	//int array[] = { 1, 2, 3, 4, 5 };
	//arrayFunc(array, size(array));
	//
	//int i;
	//cin >> i;
	//int* pAr = new int[i]{0};
	//arrayFunc(pAr, i);
	//delete[] pAr;
	//




	// binarySearch
	//int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//int size = sizeof(array) / sizeof(int);
	//
	//int index = binarySearch(array, size, 10);
	//cout << index << endl;




	// Сортировка вставками1 на куче
	//int n;
	//cin >> n;
	//
	//int* ar = new int[n];
	//for (int i = 0; i < n; i++)
	//{
	//	cin >> ar[i];
	//}
	//selectionSort(ar, n);
	//for (int i = 0; i < n; i++)
	//{
	//	cout << ar[i] << " ";
	//}
	//
	// Сортировка вставками2 на стеке
	//int n = 7;
	//int arr[7]{ 34, 12, 12, 1, 3, 5, 66 };
	//selectionSort(arr, n);
	//
	//for (int i = 0; i < n; i++) 
	// {
	//	cout << arr[i] << " ";
	//}

	//selectionSort2();




	// Пузырьковая сортировка но кажется не правильная! 
	// TODO:: перенести в функцию
	////const int N = 5;
	////int A[N] = { 1, 3, 2, 5, 4 };
	//
	//const int N = 5000;
	//int A[N];
	//
	//for (int i = 0; i < N; i++)
	//{
	//	//A[i] = N - 1 - i;
	//	A[i] = rand() % (i + 1);
	//}
	//
	//std::cout << "OLD:" << std::endl;
	//for (auto i : A)
	//{
	//	cout << i << "   ";
	//}
	//
	//bool is_sorted = false;
	//while (not is_sorted)
	//{
	//	int i = 0;
	//	is_sorted = true;
	//	while (i < N - 1)
	//	{
	//		if (A[i] > A[i + 1])
	//		{
	//			int tmp = A[i];
	//			A[i] = A[i + 1];
	//			A[i + 1] = tmp;
	//			is_sorted = false;
	//		}
	//		i += 1;
	//	}
	//}
	//
	//cout << endl << endl;
	//cout << "NEW:" << endl;
	//for (int i = 0; i < N; ++i)
	//{
	//	cout << A[i] << "   ";
	//}







	// Тренировка с массивами
	//const int rows = 2;
	//const int columns = 3;
	//
	//int demo2DArray[rows][columns]
	//{
	//	{4, 7, 8},
	//	{6, 5, 9}
	//};
	//
	//demo2DArray[1][2] = 1 + 1;
	//cout << demo2DArray[1][2];
	//
	//for (int i = 0; i < rows; i++)
	//{
	//	for (int j = 0; j < columns; j++)
	//	{
	//		cout << demo2DArray[i][j] << " ";
	//	}
	//	cout << endl;
	//}



	// Динамический массив на стеке!
	//int N;
	//std::cin >> N;
	//int32_t A[N]; // а в других компиляторах такое можно! - это сраная майкрасофт!
	//
	//for(int i = 0; i < N; ++i)
	//{
	//	A[i] = i;
	//}
	//
	//for( auto x : A )
	//{
	//	std::cout << A[x] <<"\t";
	//}




	// Хитрое заполнение массива
	////int N, M;      // для не майкрософт компиляторов
	////cin >> N >> M; // для не майкрософт компиляторов
	//const int N = 3;
	//const int M = 4;
	//
	//int A[N][M];
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		A[i][j] = i * M + j;
	//	}
	//}
	//
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		cout << A[i][j] << '\t';
	//	}
	//	cout << '\n';
	//}
	//
	////int *p = reinterpret_cast<int *>(A);
	//int *p = A[0];
	//for(int i = 0; i < M*N; i++)
	//{
	//	cout << *(p + i) << ' ';
	//}



	// Уебанское создание, заполнение и вывод 2D массива 
	//const int N = 3;
	//const int M = 4;
	//
	//int A[N][M_MAXIMAL];
	//
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		A[i][j] = i * M + j;
	//	}
	//}
	//
	//print_array2d(A, N, M);
	//
	//// memory investigation
	//
	////int *p = A[0];
	//int* p = reinterpret_cast<int*>(A);
	//
	//for (int i = 0; i < M * N; i++)
	//{
	//	cout << *(p + i) << ' '; // Уебанское создание 2D массива - пробема с  выводом через указатель
	//
	//}
	//
	//cout << endl;
	//
	//for (int i = 0; i < 12; i++)
	//{
	//	cout << *(p + i) << "   "; // Уебанское создание 2D массива - пробема с  выводом через указатель
	//	cout << (p + i) << "   ";
	//}



	// Нормальное создаение и вывод 2D массива через указатель
	//const int N = 3;
	//const int M = 4;
	//int A[N][M];
	//
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		A[i][j] = i * M + j;
	//	}
	//}
	//
	//print_array2d(reinterpret_cast<int*>(A), N, M);
	//// print_array2d(A[0], N, M);
	//
	//// memory investigation
	//int* p = reinterpret_cast<int*>(A);
	//for (int i = 0; i < M * N; i++)
	//{
	//	cout << *(p + i) << ' ';
	//}



	// Ещё 1 вариант правильного создание, заполнения и распечатки 2D массива линейного
	//const int N = 3;
	//const int M = 4;
	//
	//int A[N * M];
	//
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		A[i * M + j] = i * M + j;
	//	}
	//}
	//
	//print_array2d(A, N, M);
	//
	////int* p = reinterpret_cast<int*>(A);
	//int *p = A; // или так
	//for (int i = 0; i < M * N; i++)
	//{
	//	cout << *(p + i) << ' ';
	//}




	// Динамические 2D массивы - В двухмерных массивах, которые создаются как массив массивов, память не обязательно будет непрерывной.
	//int N, M;
	//cin >> N >> M; // вот теперь это работает!
	//
	//// memory allocation
	//int** A = new int* [N];
	//for (int i = 0; i < N; i++)
	//{
	//	A[i] = new int[M];
	//}
	//
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		A[i][j] = i * M + j;
	//	}
	//}
	//
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		cout << A[i][j] << '\t';
	//	}
	//	cout << '\n';
	//}
	//
	//for (int i = 0; i < N; i++)
	//{
	//	delete[] A[i];
	//}
	//delete[] A;



	// Динамические Линейные! 2D связанные массивы
	//int N, M;
	//cin >> N >> M;
	//
	//// memory allocation
	//int** A = new int* [N];
	//A[0] = new int[N * M];
	//for (int i = 1; i < N; i++)
	//{
	//	A[i] = A[0] + M * i;
	//}
	//
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		A[i][j] = i * M + j;
	//	}
	//}
	//
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		cout << A[i][j] << '\t';
	//	}
	//	cout << '\n';
	//}
	//
	//print_array2d(A[0], M, N);
	//
	//int* p = A[0];
	//for (int i = 0; i < M * N; i++)
	//{
	//	cout << *(p + i) << ' '; //это тоже будет работать
	//}
	//
	//delete[] A[0];
	//delete[] A;




	// Подход 2: Использование двумерного массива с непрерывной памятью, можно выделить память как для непрерывного блока
	// На мой взгляд самый нормальный и понятный подход!
	//int N, M;
	//cin >> N >> M;
	//
	//// выделение памяти для двумерного массива в виде непрерывного блока
	//int* data = new int[N * M];
	//int** A = new int* [N];
	//for (int i = 0; i < N; i++) {
	//	A[i] = &data[i * M];
	//}
	//
	//// заполнение массива
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		A[i][j] = i * M + j;
	//	}
	//}
	//
	//// вывод массива в main
	//cout << "Array in main:\n";
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		cout << A[i][j] << '\t';
	//	}
	//	cout << '\n';
	//}
	//
	//// вызов функции print_array2d
	//cout << "\nArray in print_array2d:\n";
	//print_array2d(data, N, M);
	//
	//int* p = A[0];
	//for (int i = 0; i < M * N; i++)
	//{
	//	cout << *(p + i) << ' '; //это тоже будет работать
	//}
	//
	//// освобождение памяти
	//delete[] A;
	//delete[] data;














	std::cout << "END" << std::endl;
	return 0;
}