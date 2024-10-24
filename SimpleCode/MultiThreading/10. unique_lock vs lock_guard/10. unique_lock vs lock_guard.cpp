// 10. unique_lock vs lock_guard

#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;

void print(char&& ch)
{
	//std::unique_lock<std::mutex> ul(mtx); // оболочка над мьютексом - вызывается lock при создании в конструкторе, анлок в деструкторе как и у lock_guard
	std::unique_lock<std::mutex> ul(mtx, std::defer_lock); // std::defer_lock - не вызовется lock в конструкторе 

	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	ul.lock(); // можно кастомно лочить unique_lock, если был std::defer_lock

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

	ul.unlock(); // можно кастомно анлочить unique_lock

	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

int main()
{
	setlocale(LC_ALL, "ru");

#if 1
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