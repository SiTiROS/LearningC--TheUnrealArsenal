// 236. The printf() Function

//#include <cstdio>
#include <iostream>
#include <string>


int main()
{
#if 0
	const char C_String[]{ "Hello" };
	std::string stdString{ "Hello" };

	std::printf("hello%c\n", '!');
	std::printf("%s\n", "Hello");
	std::printf("%s\n", C_String);
	std::printf("%s\n", stdString.c_str());
	std::printf("%%\n");
#endif

#if 0
	const char C_String[]{ "Hello" };

	int charsWritten = std::printf("%s\n", C_String);

	std::cout << charsWritten << std::endl;
#endif

#if 0
	std::printf("Decimal:\t%i\n", 255);
	//std::printf("Decimal:\t%d\n", 255);
	//std::printf("Unsigned Decimal:%u\n", 255);

	std::printf("Hexadecimal:\t%X\n", 255);		//FF
	std::printf("Octal:\t\t%o\n", 255);			//377

	std::printf("Hexadecimal:\t%#x\n", 255);	//0Xff
	std::printf("Hexadecimal:\t%#X\n", 255);	//0XFF
	std::printf("Octal:\t\t%#o\n", 255);		//0377
#endif

#if 0
	int num = 255;

	std::printf("Decimal:%i\n", num);
	std::printf("Decimal:% i\n", num);
	std::printf("Decimal:%+i\n", num);

	std::printf("\nField Width:\n");
	std::printf("Decimal:%10i\n", num);
	std::printf("Decimal:%+10i\n", num);
	//left justify
	std::printf("Decimal:%-10i\n", num);
#endif

#if 1
	int num = 255;

	std::printf("Field Width...\n");
	std::printf("Integral - prepend blanks:%+10d\n", num);
	//Precede with zeros...
	std::printf("Integral - prepend zeroes:%010d\n", num);
	//Left justify
	std::printf("Integral --- left justify:%-10d\n", num);

	double pi = 3.14159265;
	std::printf("\nFloating Point:%f\n", pi);
	std::printf("Floating Point:%10f\n", pi);
	//Change precision
	std::printf("Floating Point - precision of 8:%10.8f\n", pi);
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}