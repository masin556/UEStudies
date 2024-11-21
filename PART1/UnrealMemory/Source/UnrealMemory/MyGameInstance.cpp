// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Student.h"
#include "StudentManager.h"

void CheckUObjectIsValid(const UObject* InObject, const FString& InTag)
{
	// 로그가 출력되기 위해 인자로 받은 InObject가 유효한지 아닌지 확인해야하는데
	// 일반적인 콘텐츠 제작에서 IsValid로 유효성을 테스트 하나
	// 조금더 정교한 것을 사용 IsValidLowLevel() = nullptr 까지 함께 체크해서 안심하고 쓸 수 있다
	if (InObject->IsValidLowLevel())
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] 유효한 언리얼 오브젝트"), *InTag);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] 유효하지 않은 언리얼 오브젝트"), *InTag);
	}
}

// NULL 값인지 아닌지 체크하는 함수
void CheckUObjectIsNull(const UObject* InObject, const FString& InTag)
{
	if (nullptr == InObject)
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] 널 포인터 언리얼 오브젝트"), *InTag);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] 널 포인터가 아닌 언리얼 오브젝트"), *InTag);
	}
}

void UMyGameInstance::Init()
{
	Super::Init();

	NonPropStudent = NewObject<UStudent>();
	PropStudent = NewObject<UStudent>();

	NonPropStudents.Add(NewObject<UStudent>());
	PropStudents.Add(NewObject<UStudent>());

	// 인스턴스 생성
	StudentManager = new FStudentManager(NewObject<UStudent>()); // Manager는 일반 C++ 객체여서 UObject를 관리할 수 있는 능력이 전혀 없다.
}
/*
 * 일반 C++ 객체를 사용하게 되면 UPROPERTY()와 같은것 같은 것을 사용할 수 없게 된다.
 * Unreal Object를 관리할 수 있는 능력이 안되기 때문에, Unreal 의 Garbage Collection에 의해 회수 될 것이다.
 */

void UMyGameInstance::Shutdown()
{
	Super::Shutdown();

	//studentManager가 가지고 있는 Unreal OBject가 여전히 유효한지
	const UStudent* StudentInManager = StudentManager->GetStudent();

	delete StudentManager;
	StudentManager = nullptr;

	// Manager가 지워졌을 때 여전히 유효한지 확인
	// 2. 언리얼 가비지컬렉션에게 일반 C++객체를 관리하겠다 명명하면 유효한 객체가 된다.
	CheckUObjectIsNull(StudentInManager, TEXT("StudentInManager")); // LogTemp: [StudentInManager] 널 포인터가 아닌 언리얼 오브젝트 , LogTemp: [StudentInManager] 널 포인터가 아닌 언리얼 오브젝트

	CheckUObjectIsValid(StudentInManager, TEXT("StudentInManager")); //LogTemp : [StudentInManager] 유효하지 않은 언리얼 오브젝트, LogTemp: [StudentInManager] 유효한 언리얼 오브젝트

	// 위 두가지 멤버변수가 어떻게 찍히는지 로그로
	//CheckUObjectIsNull(NonPropStudent, TEXT("NonPropStudent"));
	//CheckUObjectIsValid(NonPropStudent, TEXT("NonPropStudent"));

	CheckUObjectIsNull(PropStudent, TEXT("PropStudent"));
	CheckUObjectIsValid(PropStudent, TEXT("PropStudent"));

	/* 이후 프로젝트 셋팅에서 가비지 컬렉션이 기본 61.1초 정도로 설정되어있는데
	 * 3초로 하고 에디터를 재시작해주어야 한다.
	 * 우리가 그냥 null포인터인지 아닌지만 보고 이것이 유효하다 안유효하다고하고 진행하면 댕글링포인터가 발생한다.
	 */

	// 2.
	CheckUObjectIsNull(NonPropStudents[0], TEXT("NonPropStudents"));
	CheckUObjectIsValid(NonPropStudents[0], TEXT("NonPropStudents"));

	CheckUObjectIsNull(PropStudents[0], TEXT("PropStudents"));
	CheckUObjectIsValid(PropStudents[0], TEXT("PropStudents"));
}
