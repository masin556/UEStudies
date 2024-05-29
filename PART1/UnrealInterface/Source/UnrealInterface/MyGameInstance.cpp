// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"
#include "NoneHuman.h"

UMyGameInstance::UMyGameInstance()
{
	SchoolName = TEXT("기본학교");
}

void UMyGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("====================================="));
	UNoneHuman* Human = NewObject<UNoneHuman>(); //test
	// 각 오브젝트 TArray에 묶기 (이곳에 만들어준 Object를 넣어 묶어 줘야한다)
	TArray<UPerson*> Persons = { NewObject<UStudent>(), NewObject<UTeacher>(), NewObject<UStaff>(), Human};


	//동적가변배열을 통한 것은 ranged for 문 사용하면 Iterate(순회) 할 수 있다)
	for (const auto Person : Persons)
	{
		UE_LOG(LogTemp, Log, TEXT("구성원 이름 : %s"), *Person->GetName());
	}
	UE_LOG(LogTemp, Log, TEXT("====================================="));

	// 인터페이스 함수 돌려보기
	for (const auto Person : Persons)
	{
		//Person에 대해서 ILessonInterface로 형변환 진행
		ILessonInterface* LessonInterface = Cast<ILessonInterface>(Person);
		if (LessonInterface) //이것이 만약 성공하면 인터페이스 구현이 되어있다는 것
		{
			UE_LOG(LogTemp, Log, TEXT("%s님은 수업에 참여할 수 있습니다."), *Person->GetName());
			LessonInterface->DoLesson();
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("%s님은 수업에 참여할 수 없습니다."), *Person->GetName());
		}
	}
	UE_LOG(LogTemp, Log, TEXT("====================================="));


}
