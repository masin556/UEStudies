// Fill out your copyright notice in the Description page of Project Settings.


#include "Student.h"

UStudent::UStudent()
{
	Name = TEXT("이학생");
	Year = 1;
	Id = 1; 
} // 이런 기본 값을 설정하게 되면 , Class Default Object가 다시 생성되야 하기에 컴파일을 해주자.(처음 입력시)

void UStudent::DoLesson()
{
	Super::DoLesson();
	
	UE_LOG(LogTemp, Log, TEXT("%d학년 %d번 %s님이 수업을 듣습니다."), Year, Id, *Name/*FString 사용을 위한 포인터*/);
}
