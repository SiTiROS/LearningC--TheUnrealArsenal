// 6. Using Mutex for Thread Synchronization

#include <iostream>
#include <thread>
#include <mutex>
#include "SimpleTimer.h"

std::mutex mtx; // создание объекта мьютекса

void print(char ch)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	mtx.lock(); //лочит тред

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			std::cout << ch;
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	mtx.unlock(); // анлочит тред
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

int main()
{
	setlocale(LC_ALL, "ru");

#if 1
	SimpleTimer timer;

	std::thread th1(print, '*');
	std::thread th2(print, '#');

	th1.join();
	th2.join();
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}