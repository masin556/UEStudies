// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Person.h"
#include "LessonInterface.h"
#include "NoneHuman.generated.h"

/**
 *
 */
UCLASS()
class UNREALCOMPOSITION_API UNoneHuman : public UPerson, public ILessonInterface
{
	GENERATED_BODY()

public:
	UNoneHuman();

	virtual void DoLesson() override;
};
