// 183. Lambda Expressions

#include <iostream>
using namespace std;

int addition(int x, int y) { return (x + y); }

int main()
{
#if 0
	[]() {cout << "Hello" << endl; }; // не вызовется 
	[]() {cout << "Hello" << endl; }();
	[] { cout << "Hello" << endl; }();

	int a{ 5 }, b{ 3 };
	cout << addition(a, b) << endl;
	cout << [](int x, int y) {return (x + y); }(a, b) << endl;

	auto hi = []() {cout << "Hi" << endl; };
	hi();

	auto sum = [](int x, int y) {return (x + y); };
	cout << sum(a, b) << endl;
	cout << sum(1, 2) << endl;

#endif

#if 0
	auto div = [](int x, int y) -> double // -> double явное указание типа возврата
	{
		if (true)
		{
			return (double(x) / y);
		}
		return (x / y);
	};
	cout << div(3, 2) << endl;

#endif

#if 1
	auto div = [](auto x, auto y)
	{ return (x / y); };

	cout << div(3, 2) << endl;
	cout << div(3.5, 2) << endl;

	auto result = [](auto x, auto y)
	{ return (x / y); }(5.0, 2);

	cout << result << endl;

#endif


#if 0
#endif
	std::cout << "END\n";
	return 0;
}