// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	Super::Init();

	// integer TArray
	const int32 ArrayNum = 10;
	TArray<int32> Int32Array;

	for (int32 ix = 1; ix <= ArrayNum; ++ix)
	{
		Int32Array.Add(ix);
	} // integer 형태는 Add() or Emplace()
}
