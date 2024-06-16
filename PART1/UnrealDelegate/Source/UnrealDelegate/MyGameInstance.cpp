// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"
#include "Card.h"

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
	* MyGameInstance로 선언해주면 CourseInfo는 MyGameInstance의 SubObject가 되고
	* MyGameInstance는 CourseInfo의 Outer가 되는 컴포지션관계를 설정할 수 있다.
	*/


	UE_LOG(LogTemp, Log, TEXT("====================================="));

	// 학생들
	UStudent* Student1 = NewObject<UStudent>();


	UE_LOG(LogTemp, Log, TEXT("====================================="));


}
