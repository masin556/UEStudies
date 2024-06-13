// Fill out your copyright notice in the Description page of Project Settings.
/* 학사 정보를 담은 클래스입니다. */
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CourceInfo.generated.h"

/* 델리게이트 선언 보통 선언시 뒤쪽에 Signature라는 접두사 사용
*	2개 인수 선언
*/
DECLARE_MULTICAST_DELEGATE_TwoParams(FCourseInfoOnChangedSignature, const FString&, const FString&);
/**
 *
 */
UCLASS()
class UNREALDELEGATE_API UCourceInfo : public UObject
{
	GENERATED_BODY()

public:
	UCourceInfo();

	// 객체마냥 델리게이트 정보를 멤버 변수로 선언
	FCourseInfoOnChangedSignature OnChanged;


	// 델리게이트에 함수가 와서 바인딩(묶여진)된다면 이것을 송출해줘야 하는데 (내용이 변경되면 송출)
	// - 외부에서 학사 정보를 변경한다고 할 때 쓰는 함수 지정
	void ChangeCourseInfo(const FString& InSchoolName, const FString& InNewContents);

private:
	FString Contents;
};
