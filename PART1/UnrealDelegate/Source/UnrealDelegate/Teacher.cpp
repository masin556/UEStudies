// Fill out your copyright notice in the Description page of Project Settings.


#include "Teacher.h"
#include "Card.h"

UTeacher::UTeacher()
{
	Name = TEXT("신선생");
	// 이곳의 생성자는 부모 클래스의 생성자가 호출된 이후에 콜되기에 CDO를 호출할 필요없다. 
	Card->SetCardType(ECardType::Teacher); // 선생님용 카드
}

void UTeacher::DoLesson()
{
	//인터페이스 Super 키워드 사용할 수 없으니 인터페이스클래스에 있는 것을 직접 불러와준다.
	ILessonInterface::DoLesson();
	UE_LOG(LogTemp, Log, TEXT("%s님은 가르칩니다."), *Name);
}


