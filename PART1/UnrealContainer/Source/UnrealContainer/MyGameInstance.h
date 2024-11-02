// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**구조체와 Map**/
USTRUCT() // 언리얼 구조체임을 선언
struct FStudentData
{
	GENERATED_BODY()
	/*이곳에 작성하는 매크로들 public으로 끝난다 구조체의 기본 접근 지시자 (public) 사용*/

	FStudentData() // 생성자
	{
		Name = TEXT("홍길동");
		Order = -1;
	}

	// UObject와는 다르게 인자를 가진 생성자를 만들어서 사용가능 NewAPI로 생성될일이 없기 때문
	FStudentData(FString InName, int32 InOrder) : Name(InName), Order(InOrder) {}


	/*getTypeHash 함수 지정*/
	// operator== 추가
	bool operator==(const FStudentData& InOther) const
	{
		return Order == InOther.Order; // 순번이 같으면 같다 임시로 정해둠
	}

	// GetTypeHash 대한 선언 전역함수로 선언도 가능하며, friend 키워드를 사용해서 안쪽에 선언하면 깔끔
	friend FORCEINLINE uint32 GetTypeHash(const FStudentData& InStudentData)
	{
		// 이미 가지고 있는 integer Order에 대한 해시값을 리턴 해주어 student에 대한 해시값지정
		return GetTypeHash(InStudentData.Order);
	}


	/*public으로 빠르게 접근을 위해 Name과 순번 필드 선언*/
	// 리플렉션으로 조회 및 관리하고 싶다면 UPROPERY() 사용
	UPROPERTY()
	FString Name;

	UPROPERTY()
	int32 Order;

	/**
	* UPROPERTY() 를 넣을 때는 명확한 목적이 필요하다.(넣어도 안넣어도된다)
	* 1. 추후 리플렉션을 통해 보여진다던가
	* 2. 언리얼에디터의 스크립트 랭귀지인 Blueprint랑 호환을 시킨다든가
	* 3. !!언리얼 오브젝트 포인터를 멤버변수로 가진다면 반드세 UPROPERTY()를 써야한다.
	*/



};
/**
 *
 */
UCLASS()
class UNREALCONTAINER_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;


private:
	// 300명 학생을 담을 컨테이너 선언
	TArray<FStudentData> StudentsData;
	/*private:로 선언했는데 이 경우 값타입이라 메모리를 관리할 필요없다.
	* 리플렉션기능으로 뭔가 조회하지 않는다면 UPROPERTY()를 선언할 필요 없다.
	* 데이터를 관리할 목적으로만 선언시 이렇게 선언한다.
	*/


/*주의TArray로 관리 Student.h .cpp*/

private:
	// 언리얼 오브젝트 .h에서 언리얼 오브젝트 포인터를 선언할 때 TObjectPtr로 감싸줘야한다.
	UPROPERTY() // UObject를 TArray로 다룰때 메모릴 관리를 위해 반드시 붙여줘야한다.
	TArray<TObjectPtr<class UStudent>> Students;

	/*TMap사용*/

	TMap<int32, FString> StudentsMap;
	// key 나 Value에 Unreal Object Pointer가 들어가게되면 UPROPERTY()를 반드시 선언해줘야 하는데 그것이 없다면 선언을 안해줘도 된다.
};
