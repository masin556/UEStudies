// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	Super::Init();

	static const TCHAR LogCharArray[] = TEXT("Hello Unreal");
	UE_LOG(LogTemp, Log, LogCharArray);

	FString LogCharString = LogCharArray;
	UE_LOG(LogTemp, Log, TEXT("%s"), *LogCharString);

	//TCHAR 에 FString 포인터 연산자로 가져오기
	const TCHAR* LongCharPtr = *LogCharString;
	//직접 접근해서 사용하고 싶을시
	TCHAR* LogCharDataPtr = LogCharString.GetCharArray().GetData();


	// 다시 배열로 가지고 오고싶을 경우
	TCHAR LogCharArrayWithSize[100];
	FCString::Strcpy(LogCharArrayWithSize, LogCharString.Len(), *LogCharString); //저수준라이브러리를 사용해서 효율을 높임

	if (LogCharString.Contains(TEXT("unreal"), ESearchCase::IgnoreCase))
	{
		int32 Index = LogCharString.Find(TEXT("unreal"), ESearchCase::IgnoreCase);
		FString EndString = LogCharString.Mid(Index); // unreal이 시작된 위치에서부터 끝까지 잘라주게됨
		UE_LOG(LogTemp, Log, TEXT("Find Test : %s"), *EndString);
	}

	FString Left, Right; // 서브클래스 생성
	if (LogCharString.Split(TEXT(" "), &Left, &Right))
	{
		UE_LOG(LogTemp, Log, TEXT("Split Test: %s 와 %s"), *Left, *Right);
	}


	int32 IntValue = 32;
	float FloatValue = 3.141592;

	//가장 편한 방식
	FString FloatIntString = FString::Printf(TEXT("Int : %d Float : %f"), IntValue, FloatValue);

	//단일 value -> string 변환 FString에서 제공하는 float (SanitizerFloat)
	FString IntString = FString::FromInt(IntValue);
	FString FloatString = FString::SanitizeFloat(FloatValue);

	UE_LOG(LogTemp, Log, TEXT("%s"), *FloatIntString);
	UE_LOG(LogTemp, Log, TEXT("Int : %s Float : %s"), *IntString, *FloatString);


	//floatstring값을 -> integer로 변환 FCString에서 제공하는 함수 사용
	int32 IntValueFromString = FCString::Atoi(*IntString);
	float FloatValueFromString = FCString::Atof(*FloatString);

	FString FloatIntString2 = FString::Printf(TEXT("Int : %d Float : %f"), IntValueFromString, FloatValueFromString);
	UE_LOG(LogTemp, Log, TEXT("%s"), *FloatIntString2);


	//FName 비교하기
	FName key1(TEXT("PELVIS"));
	FName key2(TEXT("pelvis"));
	UE_LOG(LogTemp, Log, TEXT("FName 비교 결과 : %s"), key1 == key2 ? TEXT("같음") : TEXT("다름"));

	//주의할 점
	for (int i = 0; i < 10000; ++i)
	{
		FName SearchInNamePool = FName(TEXT("pelvis"));
		const static FName StaticOnlyOnce(TEXT("pelvis"));
	}
}
