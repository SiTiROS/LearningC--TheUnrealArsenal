// 5. Threads and class methods

#include <iostream>
#include <thread>

class myClass
{
public:

	void doWork()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "ID потока = " << std::this_thread::get_id() << " --------- \tsum STARTED\t --------- " << std::endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::cout << "ID потока = " << std::this_thread::get_id() << " --------- \tsum STOPPED\t --------- " << std::endl;
	}

	void doWork2(int a)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "ID потока = " << std::this_thread::get_id() << " --------- \tsum STARTED\t --------- " << std::endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::cout << "doWork2: " << a << std::endl;
		std::cout << "ID потока = " << std::this_thread::get_id() << " --------- \tsum STOPPED\t --------- " << std::endl;
	}

	int sum(int a, int b)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "ID потока = " << std::this_thread::get_id() << " --------- \tsum STARTED\t --------- " << std::endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::cout << "ID потока = " << std::this_thread::get_id() << " --------- \tsum STOPPED\t --------- " << std::endl;
		return a + b;
	}

	int sumRef(int& a, int& b)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "ID потока = " << std::this_thread::get_id() << " --------- \tsum STARTED\t --------- " << std::endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::cout << "ID потока = " << std::this_thread::get_id() << " --------- \tsum STOPPED\t --------- " << std::endl;
		return a + b;
	}
};


int main()
{
	setlocale(LC_ALL, "ru");

#if 0
	int result{};

	myClass m;

	std::thread th([&]()
		{
			result = m.sum(1, 2);
		});

	for (size_t i = 1; i <= 10; i++)
	{
		std::cout << "ID потока = " << std::this_thread::get_id() << "\tmain\t" << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	th.join();
	std::cout << result << std::endl;
#endif

#if 0
	int result{};

	myClass m;

	std::thread th(&myClass::doWork, m); // передача объекта и вызов его метода в поток

	for (size_t i = 1; i <= 10; i++)
	{
		std::cout << "ID потока = " << std::this_thread::get_id() << "\tmain\t" << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	th.join();
#endif

#if 1
	int result{};

	myClass m;

	std::thread th(&myClass::doWork2, m, 1); // передача объекта и вызов его метода в поток

	for (size_t i = 1; i <= 10; i++)
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