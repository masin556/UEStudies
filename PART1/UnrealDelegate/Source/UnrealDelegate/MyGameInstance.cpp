// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"
#include "Card.h"
#include "CourseInfo.h"

UMyGameInstance::UMyGameInstance()
{
	SchoolName = TEXT("학교");
}

void UMyGameInstance::Init()
{
	Super::Init();
	/* CourseInfo를 CDO안에서 생성할 수도 있으나, 외부에서 필요할 때만 생성하도록 처리
	*	학사정보는 당연히 필요한 것이라 생성자에 선언하는 것도 맞다.
	*/
	CourseInfo = NewObject<UCourseInfo>(this);
	/** 첫번째 인자를 Outer로 지정가능 생성한 객체는 클래스 멤버 변수에 들어가서
	*관리를 받고 특별한 일이 있지 않는 한 메모리에 계속 유지가 될 것이다.
	* 이때 MyGameInstance는 CourseInfo를 포함해주어야 한다 그렇기 때문에 Outer를 현재
	* MyGameInstance로 선언해주면 CourseInfo는 MyGameInstance의 서브오브젝트가 되고
	* MyGameInstance는 CourseInfo의 Outer가 되는 컴포지션 관계를 설정할 수 있다.
	*/


	UE_LOG(LogTemp, Log, TEXT("====================================="));

	// 학생들
	/*이 구문이 실행되면 여기 오브젝트들은 자동으로 소멸되기 때문에 굳이 Outer를 설정해줄 필요없다.*/
	UStudent* Student1 = NewObject<UStudent>();
	Student1->SetName(TEXT("학생1"));
	UStudent* Student2 = NewObject<UStudent>();
	Student2->SetName(TEXT("학생2"));
	UStudent* Student3 = NewObject<UStudent>();
	Student3->SetName(TEXT("학생3"));


	/*
	* AddUObject 클래스 인스턴스를 지정하고 멤버함수를 직접 묶을 수 있다.
	* AddUObject(인스턴스, 인스턴스가 가진 클래스 멤버함수를 레퍼런스로&)
	*/
	CourseInfo->OnChanged.AddUObject(Student1, &UStudent::GetNotification);
	CourseInfo->OnChanged.AddUObject(Student2, &UStudent::GetNotification);
	CourseInfo->OnChanged.AddUObject(Student3, &UStudent::GetNotification);

	// CourseInfo 변경
	CourseInfo->ChangeCourseInfo(SchoolName, TEXT("변경된 학사 정보"));

	UE_LOG(LogTemp, Log, TEXT("====================================="));


}
