// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TestObject.generated.h"

// UCLASS() // у object нет ничего

// UCLASS(Blueprintable) // позволяет создавать Blueprint-наследников от класса,
// что особенно полезно для классов, в которых нужно расширять логику или добавлять функционал в визуальном редакторе.

//UCLASS(BlueprintType) // делает класс доступным как тип данных в Blueprints,
//но не разрешает создавать Blueprint-наследников от этого класса.

UCLASS(BlueprintType, Blueprintable)
class CPPEXPERIMENTS_API UTestObject : public UObject
{
	GENERATED_BODY()

public:
	UTestObject();

	UFUNCTION(BlueprintCallable)
	void Hello();

	UPROPERTY(BlueprintReadWrite)
	uint8 Health;

protected:
private:
};