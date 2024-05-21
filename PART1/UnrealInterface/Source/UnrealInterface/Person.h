// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.generated.h"

/**
 *
 */
UCLASS()
class UNREALINTERFACE_API UPerson : public UObject
{
	GENERATED_BODY()

public:
	UPerson();

	FString& GetName() { return Name; }
	void SetName(const FString& InName) { Name = InName; }

protected:
	//이름속성추가
	UPROPERTY()
	FString Name;




};