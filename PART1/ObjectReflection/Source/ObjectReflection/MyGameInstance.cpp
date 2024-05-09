// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"
#include "Student.h"
#include "Teacher.h"

UMyGameInstance::UMyGameInstance()
{
	SchoolName = TEXT("기본학교");
}

void UMyGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("=============================")); //구분선
	/* UMyGameInstance에 대한 클래스 정보를 얻어오기(런타임, 컴파일타임) */

	// 1. UMyGameInstance에 대한 클래스 정보를 런타임에서 얻을수 있다.
	UClass* ClassRuntime = GetClass();

	// 2. StaticClass 함수를 호출해서 해당 클래스 정보를 불러올 수 있다.
	UClass* ClassCompile = UMyGameInstance::StaticClass();

	// 위 둘은 동일한 객체를 가리키고 있다.
	// 정말 동일한지 if문으로도 가능하나 같지 않을 경우 문제가 발생할 수 있다.
	// 반드시 검증하고 넘어가야 되는 상황이 발생할 때 check 어설션(Assertion)함수를 사용하자
	// check(ClassRuntime == ClassCompile);

	// 에디터의 꺼짐의 번거로움을 없애고 오류를 확인가능하다.
	//ensure(ClassRuntime != ClassCompile);

	// 메세지를 남기고 싶을때
	//ensureMsgf(ClassRuntime != ClassCompile, TEXT("일부러 에러를 발생시킨 코드"));


	// check 통과시 로그를 볼 수 있다.
	UE_LOG(LogTemp, Log, TEXT("학교를 담당하는 클래스 이름 : %s"), *ClassRuntime->GetName()/*class이름*/);

	SchoolName = TEXT("언리얼 월드!");

	UE_LOG(LogTemp, Log, TEXT("학교 이름 : %s"), *SchoolName);
	UE_LOG(LogTemp, Log, TEXT("학교 이름 기본값 : %s"), *GetClass()->GetDefaultObject<UMyGameInstance>()->SchoolName);

	UE_LOG(LogTemp, Log, TEXT("=============================")); //구분선

	// Object 클래스 불러오기 및 생성
	UStudent* Student = NewObject<UStudent>();
	UTeacher* Teacher = NewObject<UTeacher>();

	// 언리얼 오브젝트 객체가 갖고 있는 멤버 변수값을 변경
	/* Person에서 구현된 GetName(), SetName()을 사용해서 속성정보 변경 */
	Student->SetName(TEXT("학생1"));
	UE_LOG(LogTemp, Log, TEXT("새로운 학생 이름 %s"), *Student->GetName());

	// 위처럼 GET SET 함수를 사용할 수도 있지만. 언리얼엔진이 제공하는 리플렉션 시스템을 사용해서도 변경이 가능하다.
	// 리플렉션 시스템 사용

	FString CurrentTeacherName;
	FProperty* NameProp = UTeacher::StaticClass()->FindPropertyByName(TEXT("Name"));
	if (NameProp)
	{
		NameProp->GetValue_InContainer(Teacher, &CurrentTeacherName);
		UE_LOG(LogTemp, Log, TEXT("현재 선생님 이름 %s"), *CurrentTeacherName);
	}
}
