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

}
