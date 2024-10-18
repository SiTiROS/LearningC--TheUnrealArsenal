// 2. Threads with parameters. Passing parameters to a thread

#include <iostream>
#include <thread>
#include <chrono>

void doWork(int a, int b, std::string msg)
{
	std::cout << msg << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	std::cout << "\t--- doWork STARTED ---\t" << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	std::cout << "a + b = " << a + b << std::endl;

	using namespace std::chrono_literals;
	std::this_thread::sleep_for(3s); // С++ 14 альтернативный вариант передачи времени, но надо подключить пространство имён
	std::cout << "\t--- doWork STOPPED ---\t" << std::endl;
}


int main()
{
	setlocale(LC_ALL, "ru");

#if 1
	std::thread th(doWork, 2, 3, "Our message");

	for (size_t i = 0; true; i++)
	{
		std::cout << "ID потока = " << std::this_thread::get_id() << "\tmain\t" << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	th.join();
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}