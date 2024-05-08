// Fill out your copyright notice in the Description page of Project Settings.


#include "Person.h"

UPerson::UPerson()
{
	// 기본 값 지정
	Name = TEXT("홍길동");
	Year = 1; // 연차정보
}

void UPerson::DoLesson()
{
	UE_LOG(LogTemp, Log, TEXT("%s님이 수업에 참여합니다."), *Name);
}

const FString& UPerson::GetName() const
{
	return Name;
}

void UPerson::SetName(const FString& InName)
{
	Name = InName;
}
