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

// 이 Course랑 함께 어떠한 것도 연결되어있지 않다. 이 중재하는 것을 MyGameInstance에서 진행
void UStudent::GetNotification(const FString& School, const FString& NewCourseInfo)
{
	UE_LOG(LogTemp, Log, TEXT("[Student] %s님이 %s로 부터 받은 메시지 : %s"), *Name, *School, *NewCourseInfo);
}
