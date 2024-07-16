// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Algo/Accumulate.h" // 합계를 구하는 Accumulate() 함수를 사용할 수 있다.

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


	/*for문으로 합을 구하는데 아래와 같은 구문으로 사용하면 아래와 같다.
	* 이때 Accumulate헤더를 추가해서 합을 간단히 계산 할 수있다.
	*/
	int32 Sum = 0;
	for (const int32& Int32Elem : Int32Array)
	{
		Sum += Int32Elem;
	}

	ensure(Sum == 55);

	/*Accumulate() 사용*/
	int32 SumByAlgo = Algo::Accumulate(Int32Array, 0);
	ensure(Sum == SumByAlgo);


	/** TSet을 활용한 */
	TSet<int32> Int32Set;
	for (int32 ix = 1; ix <= ArrayNum; ++ix)
	{
		Int32Set.Add(ix); // Add(), or Emplace / 프리미티브 타입(Primitive Type)이니 Add
	}

	// RemoveAll 함수가 없기에 하나씩 제거
	Int32Set.Remove(2);
	Int32Set.Remove(4);
	Int32Set.Remove(6);
	Int32Set.Remove(8);
	Int32Set.Remove(10);

	// 다시 추가
	Int32Set.Add(2);
	Int32Set.Add(4);
	Int32Set.Add(6);
	Int32Set.Add(8);
	Int32Set.Add(10);

	/*위 TArray와 TSet이 어떻게 다른지 확인해보자 */
}
