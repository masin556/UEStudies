// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

struct FStudentData
{
	FStudentData() {}
	// 인자를 받는 생성자
	FStudentData(int32 InOder, const FString& InName) : Order(InOder), Name(InName) {}

	int32 Order = -1;
	FString Name = TEXT("홍길동");
};
/**
 * 
 */
UCLASS()
class UNREALSERIALIZATION_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UMyGameInstance();

	virtual void Init() override;
};
