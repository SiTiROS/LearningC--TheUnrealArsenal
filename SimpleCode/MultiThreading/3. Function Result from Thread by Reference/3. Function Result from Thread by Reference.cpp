// 3. Function Result from Thread by Reference

#include <iostream>
#include <thread>
//#include <chrono>

void doWork(int& a)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "ID потока = " << std::this_thread::get_id() << " --------- \tdoWork STARTED\t --------- " << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	a *= 2;

	std::cout << "ID потока = " << std::this_thread::get_id() << " --------- \tdoWork STOPPED\t --------- " << std::endl;
}

int main()
{
	setlocale(LC_ALL, "ru");

#if 1
	int q{ 5 };

	std::thread th(doWork, std::ref(q)); // передача параметра в поток по ссылке

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "ID потока = " << std::this_thread::get_id() << "\tmain\t" << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	th.join();
	std::cout << q << std::endl;
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}