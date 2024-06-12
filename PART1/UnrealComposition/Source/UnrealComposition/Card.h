// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Card.generated.h"

// 어떤 분류에 의한 여러가지를 설정할 때 필요한 열거형 enum
/*
* E접두사를 붙여서 구분시켜주는 것 
* 열거형이 가지는 타입 8byte 바이트형태를 해주는 것이 일반적 
*/
UENUM() // 언리얼 C++ 에서 이러한 키워드 사용시 UCLASS와 같이 이 객체에 대한 정보를 언리얼엔진에서 파악해서 유용한 정보를 가져올 수 있다. 
enum class ECardType : uint8
{
	/* 필드 마다 Meta정보를 집어넣을 수 있다.*/
	Student = 1 UMETA(DisplayName = "For Student"),
	Teacher UMETA(DisplayName = "For Teacher"),
	Staff UMETA(DisplayName = "For Staff"),
	Invalid
}; // 일반 적인 C++ 방식

/**
 *
 */
UCLASS()
class UNREALCOMPOSITION_API UCard : public UObject
{
	GENERATED_BODY()

public:
	UCard();

	ECardType GetCardType() const { return CardType; }
	void SetCardType(ECardType InCardType) { CardType = InCardType; }

private:
	UPROPERTY()
	ECardType CardType;

	//id값
	UPROPERTY()
	uint32 Id;
};
