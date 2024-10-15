// 237. Streams - Section 1 Wrap-Up

#include <iostream>
#include <iomanip>

void numberRuler(int iterations = 4)
{
	for (size_t i = 0; i < iterations; i++)
	{
		std::cout << "1234567890";
	}
	std::cout << std::endl;
}

int main()
{
#if 0
	double d1{ 123.321 };
	double d2{ 123456789 };
	double d3{ 1.3e5 };

	std::cout << std::setprecision(2);
	std::cout << "Default display with Precision(2)..." << std::endl;
	std::cout << "d1: " << d1 << std::endl;
	std::cout << "d2: " << d2 << std::endl;
	std::cout << "d3: " << d3 << std::endl;

	std::cout << std::fixed;
	std::cout << "\nFixed-point notation with Precision(2)..." << std::endl;
	std::cout << "d1: " << d1 << std::endl;
	std::cout << "d2: " << d2 << std::endl;
	std::cout << "d3: " << d3 << std::endl;

	std::cout << std::scientific;
	std::cout << std::showpos << std::uppercase;
	std::cout << "\nScientific notation with Precision(2)..." << std::endl;
	std::cout << "d1: " << d1 << std::endl;
	std::cout << "d2: " << d2 << std::endl;
	std::cout << "d3: " << d3 << std::endl;
#endif

#if 0
	double d1{ -123.321 };
	double d2{ 123456789 };
	double d3{ 0.00003141159 };
	double d4{ 1.3e5 };

	std::cout.setf(std::ios::fixed);
	std::cout << "Fixed-point notation..." << std::endl;
	std::cout << "d1: " << d1 << std::endl;
	std::cout << "d2: " << d2 << std::endl;
	std::cout << "d3: " << d3 << std::endl;
	std::cout << "d4: " << d4 << std::endl;

	std::cout.flags(std::ios::scientific | std::ios::showpos);
	std::cout << "\nScientific notation..." << std::endl;
	std::cout << "d1: " << d1 << std::endl;
	std::cout << "d2: " << d2 << std::endl;
	std::cout << "d3: " << d3 << std::endl;
	std::cout << "d4: " << d4 << std::endl;

	std::cout.unsetf(std::ios::scientific | std::ios::showpos);
	std::cout << "\nRevert to Default display..." << std::endl;
	std::cout << "d1: " << d1 << std::endl;
	std::cout << "d2: " << d2 << std::endl;
	std::cout << "d3: " << d3 << std::endl;
	std::cout << "d4: " << d4 << std::endl;
#endif

#if 0
	numberRuler();
	std::cout << "Hello" << std::endl;

	numberRuler();
	std::cout << std::setw(10) << "Hello" << std::endl;

	numberRuler();
	std::cout << std::setw(10) << std::left << "Hello" << std::endl;

	numberRuler();
	std::cout << std::setfill('-');
	std::cout << std::setw(10) << std::left << "Hello" << "Bob" << std::endl;
#endif

#if 0
	const char* name1 = u8"Adam";
	const wchar_t* name2 = L"Addams";

	std::cout << name1 << std::endl;
	std::wcout << name2 << std::endl;
#endif

#if 1
	using namespace std::string_literals; // for the s-suffix

	const char* cStr = "Adam";
	const wchar_t* wcStr = L"Addams";

	std::string str1 = "Hello";
	std::wstring wStr1 = L"Hello";

	std::string str2 = R"("Hello \ Human!")";
	std::wstring wStr2 = LR"("Hello \ Human!")";

	//std::wstring wStr3 = L"Hello" + L" Human!";
	//std::wstring wStr4 = L"Hello's + L" Human!";

	std::cout << cStr << std::endl;
	std::wcout << wcStr << std::endl;
	std::cout << str1 << std::endl;
	std::wcout << wStr1 << std::endl;
	std::cout << str2 << std::endl;
	std::wcout << wStr2 << std::endl;
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}