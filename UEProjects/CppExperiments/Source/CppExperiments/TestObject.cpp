// Fill out your copyright notice in the Description page of Project Settings.

#include "TestObject.h"

UTestObject::UTestObject()
{
	Health = 100;
}

void UTestObject::Hello()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello!"));
}