// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
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

	// check 통과시 로그를 볼 수 있다.
	UE_LOG(LogTemp, Log, TEXT("학교를 담당하는 클래스 이름 : %s"), *ClassRuntime->GetName()/*class이름*/);


	UE_LOG(LogTemp, Log, TEXT("=============================")); //구분선
}
