// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 *
 */
UCLASS()
class UNREALMEMORY_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	virtual void Shutdown() override;


private:
	// UPROPERTY()를 설정한 것과의 차이보기
	TObjectPtr<class UStudent> NonPropStudent;

	// 언리얼 오브젝트의 클래스 멤버 변수를 선언할 때 반드시 UPROPERTY()를 붙여줘야 댕글링 포인터가 발생하지 않는다.
	UPROPERTY()
	TObjectPtr<class UStudent> PropStudent;

	/* 2. 자료구조 컨테이너 안에 언리얼 오브젝트로 안전하게 관리하는 방법 */
	TArray<TObjectPtr<class UStudent>> NonPropStudents;
	// TSet,TArray, TMap과 같은 Template 인자또한 UPROPERTY()를 붙여줘야 안전히 관리할 수 있다.
	UPROPERTY()
	TArray<TObjectPtr<class UStudent>> PropStudents;


	// FStudentManager

	// 일반 객체여서 UPROPERTY()를 사용할 수 없어서 값이 어떻게 될지 모르기에 nullptr 로 초기화 시켜준다.
	class FStudentManager* StudentManager = nullptr;

};
