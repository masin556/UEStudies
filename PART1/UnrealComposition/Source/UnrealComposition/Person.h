// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.generated.h"

/**
 *
 */
UCLASS()
class UNREALCOMPOSITION_API UPerson : public UObject
{
	GENERATED_BODY()

public:
	UPerson();

	FORCEINLINE const FString& GetName() const { return Name; } // 레퍼런스 지시자 가 있는 것은 const 를 넣어줘야한다.
	FORCEINLINE void SetName(const FString& InName) { Name = InName; }

	FORCEINLINE class UCard* GetCard() { return Card;  }
	FORCEINLINE void SetCard(class UCard* InCard) { Card = InCard; }

protected:
	//이름속성추가
	UPROPERTY()
	FString Name;

	UPROPERTY()
	//class UCard* Card; //Composition과 관계된 것은 전방선언을 통해 최대한 의존성을 없앨 수 있다. <전통적인 방식>
	TObjectPtr<class UCard> Card;

};
