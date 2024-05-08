// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.generated.h"

/**
 *
 */
UCLASS()
class OBJECTREFLECTION_API UPerson : public UObject
{
	GENERATED_BODY()

public:
	// 기본 값 설정을 위한 생성자 선언
	UPerson();

	// 언리얼엔진이 관리할 수 있는 가상함수 선언
	UFUNCTION()
	virtual void DoLesson(); // 가상함수 선언

	// 외부에서 프로퍼티 접근을 위한 Gether()와 Setter() 함수 선언
	const FString& GetName() const; // const로 레퍼런스를 반환하도록하고 , 변경할 것이 아니기에 const지시자 선언
	void SetName(const FString& InName); // 들어오는 인자에 대해서 레퍼런스 const 



protected:
	// protected 영역 Student와 Teacher 클래스가 받을 속성
	UPROPERTY()
	FString Name;

	UPROPERTY()
	int32 Year;

private:

};