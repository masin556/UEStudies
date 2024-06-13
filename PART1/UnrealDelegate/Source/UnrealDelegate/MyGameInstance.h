// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 *
 */
UCLASS()
class UNREALDELEGATE_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	// 기본값을 설정하는 로직은 생성자로.
	UMyGameInstance();

	// 가상함수
	virtual void Init() override;

private:

	// 학교이름 변수
	/** 해당 문자열을 언리얼엔진이 관리할 수 있도록 UPROPERTY()설정
	* schoolname에 관련된 값을 언리얼엔진이 파악하고 관리할 수 있다.
	* 리플렉션 시스템을 사용해서 SchoolName에 대한 정보를 런타임이든 컴파일타임이든 언제든지 얻어올 수 있다.
	*/
	UPROPERTY()
	FString SchoolName; // 단일 변수 사용시 언리얼의 영향을 받지 못한다.

};
