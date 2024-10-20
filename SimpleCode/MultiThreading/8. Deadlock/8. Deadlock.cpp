// 8. Deadlock

#include <iostream>
#include <thread>
#include <mutex>


std::mutex mtx1;
std::mutex mtx2;

//dead lock
void print()
{
	mtx2.lock();

	std::this_thread::sleep_for(std::chrono::milliseconds(1));

	mtx1.lock();

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			std::cout << '*';
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	mtx1.unlock();
	mtx2.unlock();
}

void print2()
{
	mtx1.lock();

	std::this_thread::sleep_for(std::chrono::milliseconds(1));

	mtx2.lock();

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			std::cout << '#';
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	mtx1.unlock();
	mtx2.unlock();
}


// isn't dead lock
void print3()
{
	mtx1.lock();

	std::this_thread::sleep_for(std::chrono::milliseconds(1));

	mtx2.lock();

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			std::cout << '*';
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	mtx1.unlock();
	mtx2.unlock();
}

void print4()
{
	mtx1.lock();

	std::this_thread::sleep_for(std::chrono::milliseconds(1));

	mtx2.lock();

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			std::cout << '#';
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	mtx1.unlock();
	mtx2.unlock();
}

int main()
{
	setlocale(LC_ALL, "ru");

#if 0

	std::thread th1(print);
	std::thread th2(print2);

	th1.join();
	th2.join();
#endif

#if 1

	std::thread th1(print3);
	std::thread th2(print4);

	th1.join();
	th2.join();
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}