// Creating a thread. Parallel execution of code

#include <iostream>
#include <thread>
#include <chrono>

void doWork()
{
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "ID потока = " << std::this_thread::get_id() << "\tdoWork\t" << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}


int main()
{
	setlocale(LC_ALL, "ru");

#if 0
	std::cout << "Start main" << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(5000)); // приостанавливает работу потока

	std::cout << std::this_thread::get_id() << std::endl; // Получаем идентификатор текущего потока

	std::cout << "Stop main" << std::endl;
#endif

#if 0
	//std::thread th(doWork); // передаём указатель на функцию
	std::thread th(&doWork);  // можно так

	//th.detach();	// разрывает связь между потоками, т.е поток выполняется самостоятельно
	//th.join();	// дождаться выполнения задачи

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "ID потока = " << std::this_thread::get_id() << "\tmain\t" << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	th.join();		//надо вызывать перед завершением программы в данном случае
#endif

#if 1
	std::thread th(doWork);
	std::thread th2(doWork);

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "ID потока = " << std::this_thread::get_id() << "\tmain\t" << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	th.join();
	th2.join();
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}