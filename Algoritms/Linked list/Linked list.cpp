#include <iostream>

#if 1
struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution //кривой
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* temp1 = reverseList(l1);
		ListNode* temp2 = reverseList(l2);

		ListNode* result1 = nullptr; // Результирующий список
		ListNode* current = nullptr; // Текущий узел результирующего списка
		int carry = 0; // Перенос для сложения

		// Основной цикл сложения
		while (temp1 != nullptr || temp2 != nullptr || carry > 0)
		{
			int sum = carry; // Инициализируем сумму текущего узла

			// Если есть узел в первом списке, добавляем его значение
			if (temp1 != nullptr)
			{
				sum += temp1->val;
				temp1 = temp1->next;
			}

			// Если есть узел во втором списке, добавляем его значение
			if (temp2 != nullptr)
			{
				sum += temp2->val;
				temp2 = temp2->next;
			}

			// Рассчитываем перенос
			carry = sum / 10;
			sum = sum % 10;

			// Создаем новый узел в результирующем списке
			ListNode* newNode = new ListNode(sum);

			// Если это первый узел, инициализируем список
			if (result1 == nullptr)
			{
				result1 = newNode;
				current = result1;
			}
			else
			{
				current->next = newNode;
				current = current->next;
			}
		}

		return reverseList(result1); // Возвращаем результат после реверса
	}

	ListNode* reverseList(ListNode* head)
	{
		ListNode* prev = nullptr;
		ListNode* current = head;

		while (current)
		{
			ListNode* nextNode = current->next; // Запоминаем следующий элемент
			current->next = prev; // Перенаправляем текущий элемент на предыдущий
			prev = current; // Обновляем предыдущий элемент
			current = nextNode; // Переходим к следующему элементу
		}
		return prev; // Новый голова списка
	}

	void printList(ListNode* head)
	{
		while (head)
		{
			std::cout << head->val << " -> ";
			head = head->next;
		}
		std::cout << "nullptr" << std::endl;
	}
};


class Solution2 // правильный
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* result1 = nullptr; // Результирующий список
        ListNode* current = nullptr; // Текущий узел результирующего списка
        int carry = 0; // Перенос для сложения

        // Основной цикл сложения
        while (l1 != nullptr || l2 != nullptr || carry > 0) 
        {
            int sum = carry; // Инициализируем сумму текущего узла

            // Если есть узел в первом списке, добавляем его значение
            if (l1 != nullptr) 
            {
                sum += l1->val;
                l1 = l1->next;
            }

            // Если есть узел во втором списке, добавляем его значение
            if (l2 != nullptr) 
            {
                sum += l2->val;
                l2 = l2->next;
            }

            // Рассчитываем перенос
            carry = sum / 10;
            sum = sum % 10;

            // Создаем новый узел в результирующем списке
            ListNode* newNode = new ListNode(sum);

            // Если это первый узел, инициализируем список
            if (result1 == nullptr) 
            {
                result1 = newNode;
                current = result1;
            } 
            else 
            {
                current->next = newNode;
                current = current->next;
            }
        }

        return result1; // Возвращаем результирующий список без реверса
    }

    void printList(ListNode* head) 
    {
        while (head) 
        {
            std::cout << head->val << " -> ";
            head = head->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main()
{
	//// Создаем первый список: 2 -> 4 -> 3
	//ListNode* l1 = new ListNode(2);
	//l1->next = new ListNode(4);
	//l1->next->next = new ListNode(3);

	//// Создаем второй список: 5 -> 6 -> 4
	//ListNode* l2 = new ListNode(5);
	//l2->next = new ListNode(6);
	//l2->next->next = new ListNode(4);

	// Создаем первый список: 2 -> 4 -> 3
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(9);

	// Создаем второй список: 5 -> 6 -> 4
	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	l2->next->next->next = new ListNode(9);

	Solution2 sol;

	std::cout << "Original lists:" << std::endl;
	sol.printList(l1);
	sol.printList(l2);

	ListNode* result = sol.addTwoNumbers(l1, l2);

	std::cout << "Result:" << std::endl;
	sol.printList(result);

	// Освобождение памяти
	delete l1->next->next;
	delete l1->next;
	delete l1;

	delete l2->next->next;
	delete l2->next;
	delete l2;

	return 0;
}
#endif




//
#if 0
struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		ListNode* dummyHead = new ListNode(0);
		ListNode* curr = dummyHead;
		int carry = 0;
		while (l1 != NULL || l2 != NULL || carry != 0) 
		{
			int x = l1 ? l1->val : 0;
			int y = l2 ? l2->val : 0;
			int sum = carry + x + y;
			carry = sum / 10;
			curr->next = new ListNode(sum % 10);
			curr = curr->next;
			l1 = l1 ? l1->next : nullptr;
			l2 = l2 ? l2->next : nullptr;
		}
		ListNode* result = dummyHead->next;
		delete dummyHead;  // Freeing the memory allocated for dummyHead
		return result;
	}
};
#endif




// Это я гавно какое то писал
#if 0

#include <iostream>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		printList(l1);
		ListNode* temp1 = reverseList(l1);
		ListNode* temp2 = reverseList(l2);

		std::cout << "test";
		printList(temp1);

		// int result;
		ListNode* result1 = nullptr;
		// // result = temp1->val + temp2->val;
		// // std::cout << result;

		// while (temp1) 
		// {
		//     result = temp1->val + temp2->val;

		//     std::cout << result << std::endl;

		//     temp1 = temp1->next;
		//     temp2 = temp2->next;
		// }

		return result1;
	}



	ListNode* reverseList(ListNode* head)
	{
		ListNode* prev = nullptr;
		ListNode* current = head;

		while (current)
		{
			ListNode* nextNode = current->next; // Запоминаем следующий элемент
			current->next = prev; // Перенаправляем текущий элемент на предыдущий
			prev = current; // Обновляем предыдущий элемент
			current = nextNode; // Переходим к следующему элементу
		}
		return prev; // Новый голова списка
	}

	int* scanList(ListNode* l)
	{
		int* temp = new int[]{};
		int i = 0;

		while (l != nullptr)
		{
			temp[i] = l->val;
			l = l->next;
			i++;
		}
		return temp;
	}

	// Функция для вывода списка
	void printList(ListNode* head)
	{
		while (head)
		{
			std::cout << head->val << " -> ";
			head = head->next;
		}
		std::cout << "nullptr" << std::endl;
	}
};


int main()
{
	const int size = 5;
	ListNode A[size];
	ListNode B[size];

	for (int i = 0; i < size; i++)
	{
		A[i].val = i + 1;
		A[i].next = (i + 1 < size) ? &A[i + 1] : nullptr; // Устанавливаем next только для корректных индексов
	}

	for (int i = 0; i < size; i++)
	{
		B[i].val = i + 1;
		B[i].next = (i + 1 < size) ? &B[i + 1] : nullptr; // Устанавливаем next только для корректных индексов
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << "A[" << i << "].val = " << A[i].val << ", A[" << i << "].next = " << A[i].next << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << "B[" << i << "].val = " << B[i].val << ", B[" << i << "].next = " << B[i].next << std::endl;
	}

	std::cout << std::endl;

	Solution sol;

	sol.printList(A);
	sol.printList(B);

	std::cout << std::endl;

	ListNode* APtr = sol.reverseList(A);
	ListNode* BPtr = sol.reverseList(B);

	sol.printList(APtr);
	sol.printList(BPtr);

	std::cout << std::endl;

	sol.addTwoNumbers(A, B);
	sol.printList(A);
	sol.printList(B);

	return 1;
}

#endif
