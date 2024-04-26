// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyObject.generated.h"
//D:\UEStudies\PART1\UnrealObject\Intermediate\Build\Win64\UnrealEditor\Inc\UnrealObject\UHT
/*위 경로에서 generated.h 파일이 어디있는지 알 수 있다.
UnrealHeaderTools로 인해서 프로젝트가 만들어질때 generated.h 파일이 생성되고 그 안에 매크로의 집합들 헤더를 구성하는 파일들
이 소스가 자동으로 만들어지고 그 만들어진 소스가 컴파일 하게 된다.
Unreal은 이전 후발주자 언어들의 기능들 좋은 기능들을 모아둔 집약체 같은 것이다.
*/

/**
 *
 */
UCLASS()
class UNREALOBJECT_API UMyObject : public UObject
{
	GENERATED_BODY()

};
