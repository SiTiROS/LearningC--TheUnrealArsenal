// 4. Lambda Expressions and Returning Thread Result

#include <iostream>
#include <thread>

int sum(int& a, int& b)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "ID потока = " << std::this_thread::get_id() << " --------- \tsum STARTED\t --------- " << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "ID потока = " << std::this_thread::get_id() << " --------- \tsum STOPPED\t --------- " << std::endl;
	return a + b;
}

int main()
{
	setlocale(LC_ALL, "ru");

#if 1
	int a{ 5 }, b{ 5 };

	int result{};
	std::thread th([&result, &a, &b]()
		{
			result = sum(a, b); 
		});

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "ID потока = " << std::this_thread::get_id() << "\tmain\t" << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	th.join();
	std::cout << result << std::endl;;

	//[&a, &b]()
	//	{
	//		std::cout << a + b << std::endl;;
	//	}();

	//[](int& a, int& b)
	//	{
	//		std::cout << a + b << std::endl;;
	//	}(a, b);
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}