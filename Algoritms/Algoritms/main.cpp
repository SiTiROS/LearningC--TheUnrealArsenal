#include <iostream>

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



int main()
{
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