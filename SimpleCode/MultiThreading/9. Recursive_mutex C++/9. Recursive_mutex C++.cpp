// 9. Recursive_mutex C++

#include <iostream>
#include <mutex>
#include <thread>

std::recursive_mutex rm;

std::mutex m;

void foo(int a)
{
	rm.lock();
	std::cout << a << " ";

	std::this_thread::sleep_for(std::chrono::milliseconds(300));

	if (a <= 1)
	{
		std::cout << std::endl;
		rm.unlock();
		return;
	}

	a--;
	foo(a);
	rm.unlock();
}

int main()
{
	setlocale(LC_ALL, "ru");

#if 0
	m.lock();
	//m.lock(); // второй лок мьютекса вызовет ошибку

	m.unlock();
#endif

#if 0
	rm.lock();
	rm.lock(); // рекурсивный мьютекс можно захватывать много раз

	rm.unlock();
	rm.unlock();// анлочить надо столько же раз, сколько и лочить
#endif

#if 1
	std::thread t1(foo, 10);
	std::thread t2(foo, 10);

	t1.join();
	t2.join();

#endif


#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}