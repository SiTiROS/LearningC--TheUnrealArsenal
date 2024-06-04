// // // // // // // // // // // // // // // // // // // // // // // // // // // // РЈРєР°Р·Р°С‚РµР»Рё Рё СЃСЃС‹Р»РєРё // // // // // // // // // // // // // // // // // // // // // // // // // // // //

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

  // РџРѕР»СѓС‡Р°РµРј СѓРєР°Р·Р°С‚РµР»СЊ РЅР° РѕР±СЉРµРєС‚
  Person *pPtr = &p;

  // РџРѕР»СѓС‡Р°РµРј СЃСЃС‹Р»РєСѓ РЅР° РѕР±СЉРµРєС‚
  Person &pRef = p;


  // Р’С‹Р·С‹РІР°РµРј РјРµС‚РѕРґ print() С‡РµСЂРµР· СѓРєР°Р·Р°С‚РµР»СЊ
  pPtr->print();

  // Р’С‹Р·С‹РІР°РµРј РјРµС‚РѕРґ print() С‡РµСЂРµР· СЃСЃС‹Р»РєСѓ
  pRef.print();
  
  
   // // // 
  
    // РџРѕР»СѓС‡Р°РµРј Р·РЅР°С‡РµРЅРёРµ РїРѕР»СЏ age С‡РµСЂРµР· СѓРєР°Р·Р°С‚РµР»СЊ
  int age = pPtr->age; // age = 10

  // РџРѕР»СѓС‡Р°РµРј Р·РЅР°С‡РµРЅРёРµ РїРѕР»СЏ name С‡РµСЂРµР· СѓРєР°Р·Р°С‚РµР»СЊ
  string name = pPtr->name; // name = "John Doe"
  
  cout << "age = " << age << endl;
  cout << "name = " << name << endl;

  // РџРѕР»СѓС‡Р°РµРј Р·РЅР°С‡РµРЅРёРµ РїРѕР»СЏ age С‡РµСЂРµР· СЃСЃС‹Р»РєСѓ
  int age2 = pRef.age; // age2 = 10

  // РџРѕР»СѓС‡Р°РµРј Р·РЅР°С‡РµРЅРёРµ РїРѕР»СЏ name С‡РµСЂРµР· СЃСЃС‹Р»РєСѓ
  string name2 = pRef.name; // name2 = "John Doe"
  
  cout << "age = " << age2 << endl;
  cout << "name = " << name2 << endl;
}

