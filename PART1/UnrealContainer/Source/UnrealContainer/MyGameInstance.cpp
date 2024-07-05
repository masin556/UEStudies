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
	} // integer 형태는 Add() or Emplace() 1~10 까지 차례대로

	/* 짝수 조건에 해당하는 구문을 람다함수로 넣는 것이 일반적이다.*/
	Int32Array.RemoveAll([](int32 Val)
		{
			return Val % 2 == 0;
		}
	); // 짝수를 모두 제거 1,3,5,7,9 만 남게 된다.

	// operator를 사용해서 다시 복구 1~10까지 복구
	Int32Array += {2, 4, 6, 8, 10}; //위에서 짝수를 제거하고 넣었기에 13579 246810으로 들어간다.


	/*바로 메모리에 접근 C스타일 */
	TArray<int32> Int32ArrayCompare;
	int32 CArray[] = { 1, 3, 5, 7, 8, 2, 4, 6, 8, 10 };

	/// Equality Operator를 사용해서 서로 같은 지 비교해 볼 수 있다.
	// 그래서 먼저 위 CArray의 배열을 TArray에 넣어줘야 한다.
	Int32ArrayCompare.AddUninitialized(ArrayNum); // 초기화 되지 않은 데이터를 빠르게 넣어준다.

	//메모리를 통해 Memcpy로 복제 , <- 이러기 위해 포인터를 가져와야한다
	// TArray.GetData() 포인터를 가져온다음, 제작한 크기만큼, sizeof(int32) * ArrayNum) 제작한 크기만큼 복제,
	FMemory::Memcpy(Int32ArrayCompare.GetData(), CArray, sizeof(int32) * ArrayNum);

	// 두 Int32Array와 Int32ArrayCompare가 같은지
	ensure(Int32Array == Int32ArrayCompare);

}
