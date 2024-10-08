// 211 - 212. Functions that Operate on C-Strings

#define _CRT_SECURE_NO_WARNINGS // this directive removes compile errors for the old functions

#include <iostream>
#include <cstring>
#include <cctype>

int main()
{
#if 0
	char name[]{ "Bruce" };
	char surname[]{ "Lee" };
	char fullName[20]{};

	// fullName = name; //not working

	// strcpy(fullName, name); //copy name into fullName
	// strcat(fullName, " ");
	// strcat(fullName, surname);

	strcpy_s(fullName, name); //copy name into fullName
	strcat_s(fullName, " ");
	strcat_s(fullName, surname);
	std::cout << fullName << std::endl; //concatenate strings - append to the end of fullName
#endif

#if 0
	char name[]{ "Bruce" };
	char surname[]{ "Lee" };
	char fullName[20]{};

	strcpy_s(fullName, name);
	// strncpy_s(fullName, name, 3); //copy 3 first symbol

	//strcat_s(fullName, " ");
	//strncat_s(fullName, surname, 3);
	//std::cout << fullName << std::endl;

	std::cout << strlen(name) << std::endl; // return numbers symbol
	std::cout << sizeof(name) << std::endl;

	strcpy_s(fullName, "Bob");
	std::cout << fullName << std::endl;

#endif

#if 0
	char name[]{ "Bruce" };
	char const* surname{ "Lee" };
	char fullName[20]{};

	std::cout << *surname << std::endl;   // ненадо разыменовывать - это то же самое что и 
	std::cout << surname[0] << std::endl; // это - так как это массив

	std::cout << surname << std::endl;    // так правильно
#endif

#if 0
	char name[]{ "Bruce" };
	const char* surname = new char[] {"Mee"};
	char fullName[20]{};

	strcpy_s(fullName, surname);
	std::cout << fullName << std::endl;

	delete[] surname;
#endif

#if 0
	//using smart pointer instead...
	const char source_C_String[]{ "Mee" };

	auto up_C_String = std::make_unique<char[]>(std::strlen(source_C_String) + 1); // +1 for 0 end symbol

	//strcpy(up_C_String.get(), source_C_String);
	strcpy_s(up_C_String.get(), std::strlen(source_C_String) + 1, source_C_String);

	std::cout << up_C_String << std::endl;

	up_C_String[0] = 'A';

	std::cout << up_C_String << std::endl;
#endif

#if 0
	char C_String[]{ "Mee1234" };

	for (size_t i = 0; i < strlen(C_String); i++)
	{
		if (isalpha(C_String[i]))
		{
			C_String[i] = toupper(C_String[i]);
		}
	}

	std::cout << C_String << std::endl;
#endif

#if 1
	char C_String1[]{ "Mee" };
	char C_String2[]{ "Mee" };

	std::cout << strcmp(C_String1, C_String2) << std::endl;

	if (strcmp(C_String1, C_String2) == 0)
	{
		std::cout << "are equal" << std::endl;
	}
	else
	{
		std::cout << "are not equal" << std::endl;
	}
#endif


#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}