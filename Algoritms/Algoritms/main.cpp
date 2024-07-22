#include <iostream>

using namespace std;


int binarySearch(int array[], int size, int item)
{
	int low = 0; // low index
	int high = size - 1; // high index

	while (low <= high)
	{
		int mid = (low + high) / 2; // mid index
		int guess = array[mid]; // value of mid index

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



int main()
{
	// binarySearch
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size = sizeof(array) / sizeof(int);

	int index = binarySearch(array, size, 10);
	cout << index << endl;


	std::cout << "END" << std::endl;
	return 0;
}