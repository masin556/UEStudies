// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Person.h"
#include "LessonInterface.h"
#include "Student.generated.h"

/**
 *
 */
UCLASS()
class UNREALDELEGATE_API UStudent : public UPerson, public ILessonInterface
{
	GENERATED_BODY()

public:
	UStudent();

	virtual void DoLesson() override;

	// Cource에 있던 똑같은 함수를 호출해줘야한다.(리턴값이 없고 FString이 두개)
	//알림정보를 받는 함수
	void GetNotification(const FString& School, const FString& NewCourseInfo);

};
