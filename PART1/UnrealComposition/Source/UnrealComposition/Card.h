// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Card.generated.h"

/**
 *
 */
UCLASS()
class UNREALCOMPOSITION_API UCard : public UObject
{
	GENERATED_BODY()

public:
	UCard();

private:
	//id값
	UPROPERTY()
	uint32 Id;


};
