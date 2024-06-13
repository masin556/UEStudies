// Fill out your copyright notice in the Description page of Project Settings.


#include "Student.h"
#include "Card.h"

UStudent::UStudent()
{
	Name = TEXT("신학생");
	Card->SetCardType(ECardType::Student);
}

void UStudent::DoLesson()
//인터페이스 함수
{
	ILessonInterface::DoLesson();

	UE_LOG(LogTemp, Log, TEXT("%s님은 수업을 듣습니다."), *Name);
}
