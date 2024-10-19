// 7. lock_guard mutex. Sync threads

#include <iostream>
#include <thread>
#include <mutex>
#include "SimpleTimer.h"

std::mutex mtx;

void print(char ch)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	std::lock_guard<std::mutex> guard(mtx); // оболочка над мьютексом - вызывается lock при создании в конструкторе, анлок в деструкторе, для лока и унлока можно юзать {}
	{
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				std::cout << ch;
				std::this_thread::sleep_for(std::chrono::milliseconds(20));
			}
			std::cout << std::endl;
		}
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	std::cout << std::endl;
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