#pragma once
#include "Character.h"
#include "Vector.h"

//class Vector; // forward declaration ��� ����������

class PlayerCharacter : public Character 
{
public:
	PlayerCharacter();
	~PlayerCharacter();

private:
	// class Vector* vec; // forward declaration � ��� �����
	//Vector* vec; // � ���������� ����� forward declaration
	Vector vec;
};