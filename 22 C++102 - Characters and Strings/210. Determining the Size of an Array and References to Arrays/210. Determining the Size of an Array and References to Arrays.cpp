// 210. Determining the Size of an Array and References to Arrays

#include <iostream>

template<typename T>
void printArr(const T arrP[], size_t sizeP)
{
	std::cout << "The element in the array are: ";

	for (int i = 0; i < sizeP; i++)
	{
		std::cout << arrP[i] << ' ';
	}
	std::cout << std::endl;
}

template<typename T, size_t arrSizeP>
void printArr2(const T(&arrP)[arrSizeP])
{
	std::cout << "The element in the array are: ";

	for (auto element : arrP)
	{
		std::cout << element << ' ';
	}

	/*for (size_t i = 0; i < arrSizeP; i++)
	{
		std::cout << arrP[i] << ' ';
	}*/

	std::cout << std::endl;
}


int main()
{
	//std::printf("test");
#if 0
	char arr[]{ 'x', 'y', 'z', '\0' };

	std::cout << "The size of the array is: " << sizeof(arr) << std::endl;
	std::cout << "The size of an element in the array is: " << sizeof(arr[0]) << std::endl;
	std::cout << "The number of elements in the array is: " << sizeof(arr) / sizeof(arr[0]) << std::endl;
	std::cout << "size() The number of elements in the array is: " << std::size(arr) << std::endl; //C++17

	printArr(arr, std::size(arr));

	/*int a;
	std::cout <<sizeof(a) << std::endl;

	size_t b;
	std::cout <<sizeof(b) << std::endl;*/
#endif

#if 1
	char arr[]{ 'x', 'y', 'z', '\0' };

	std::cout << "The size of the array is: " << sizeof(arr) << std::endl;
	std::cout << "The size of an element in the array is: " << sizeof(arr[0]) << std::endl;
	std::cout << "size() The number of elements in the array is: " << std::size(arr) << std::endl; //C++17

	printArr2(arr); // не надо передавать развер компилятор через шаблонную функцию вычисляет сам рамер как то
	printArr2<char, std::size(arr)>(arr); // так уже понятно передаём через шаблон оба параметра


	// просто foreach который работает без проблем в области видимости массива
	for (auto alphabetCharacter : arr)
	{
		std::cout << alphabetCharacter << ' ';
	}


	// ptr to array Vs aray Allias/reference
	char* ptr = arr;
	char(&arrAlias)[std::size(arr)] = arr; //ссылка на массив
	for (auto element : arrAlias)
	{
		std::cout << element << ' ';
	}
#endif


#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}