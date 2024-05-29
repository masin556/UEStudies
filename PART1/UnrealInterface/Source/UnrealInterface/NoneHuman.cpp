// Fill out your copyright notice in the Description page of Project Settings.


#include "NoneHuman.h"

UNoneHuman::UNoneHuman()
{
	Name = TEXT("거수자");
}

void UNoneHuman::DoLesson()
{
	ILessonInterface::DoLesson();
	UE_LOG(LogTemp, Log, TEXT("%s님은 위험한 사람입니다."), *Name);
}
