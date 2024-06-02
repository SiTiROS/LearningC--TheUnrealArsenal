// // // // // // // // // // // // // // // // // // // // // // // // // // // // Указатели и ссылки // // // // // // // // // // // // // // // // // // // // // // // // // // // //

#include <iostream>

using namespace std;

class Person 
{
 public:
  int age;
  string name;

  void print() 
  {
    cout << "age = " << age << endl;
    cout << "name = " << name << endl;
  }
};

int main() 
{
  Person p;
  p.age = 10;
  p.name = "John Doe";

  // Получаем указатель на объект
  Person *pPtr = &p;

  // Получаем ссылку на объект
  Person &pRef = p;


  // Вызываем метод print() через указатель
  pPtr->print();

  // Вызываем метод print() через ссылку
  pRef.print();
  
  
   // // // 
  
    // Получаем значение поля age через указатель
  int age = pPtr->age; // age = 10

  // Получаем значение поля name через указатель
  string name = pPtr->name; // name = "John Doe"
  
  cout << "age = " << age << endl;
  cout << "name = " << name << endl;

  // Получаем значение поля age через ссылку
  int age2 = pRef.age; // age2 = 10

  // Получаем значение поля name через ссылку
  string name2 = pRef.name; // name2 = "John Doe"
  
  cout << "age = " << age2 << endl;
  cout << "name = " << name2 << endl;
}

