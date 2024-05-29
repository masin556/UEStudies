// Fill out your copyright notice in the Description page of Project Settings.


#include "Teacher.h"

UTeacher::UTeacher()
{
	Name = TEXT("신선생");
}

void UTeacher::DoLesson()
{
	//인터페이스 Super 키워드 사용할 수 없으니 인터페이스클래스에 있는 것을 직접 불러와준다.
	ILessonInterface::DoLesson();
	UE_LOG(LogTemp, Log, TEXT("%s님은 가르칩니다."), *Name);
}


