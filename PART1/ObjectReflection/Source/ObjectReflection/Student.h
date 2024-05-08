// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.h"
#include "Student.generated.h"
/**
 *
 */
UCLASS()
class OBJECTREFLECTION_API UStudent : public UPerson
{
	GENERATED_BODY()

public:
	// 기본 값 생성을 위한 생성자선언
	UStudent();

	// Person에서 선언해준 DoLesson() 가상함수를 오버라이드 해준다
	
	virtual void DoLesson() override;


private:
	UPROPERTY()
	int32 Id;//학번을 나타내는 변수

};
