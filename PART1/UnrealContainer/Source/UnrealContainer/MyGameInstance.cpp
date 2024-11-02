// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Algo/Accumulate.h" // 합계를 구하는 Accumulate() 함수를 사용할 수 있다.


/*11강 구조체와 Map*/
FString MakeRandomName()
{
	// 4*4*4 = 64개의 조합으로 만들수 있는 이름*/
	TCHAR FirstChar[] = TEXT("김이박최"); // 1. 성씨 나열
	TCHAR MiddleChar[] = TEXT("상혜지성"); // 2. 성씨와 어울릴 수 있는 중간이름
	TCHAR LastChar[] = TEXT("수은원연"); // 3. 마지막에 들어갈

	// 랜덤 조합으로 이름 만들기
	TArray<TCHAR> RandArray; // TArray 경우 TChar 배열을 포함하고 있는 컨테이너
	RandArray.SetNum(3); // - SetNum()함수 공간확보 및 기본값으로 채워짐
	RandArray[0] = FirstChar[FMath::RandRange(0, 3)]; //RandArray 첫번째 배열요소에 FMath::RandRange(0, 3)으로 인덱스를 뽑아낸다.
	RandArray[1] = MiddleChar[FMath::RandRange(0, 3)];
	RandArray[2] = LastChar[FMath::RandRange(0, 3)];
	/*위 내용은 TCHAR가 3개 배열된 형태 위
	* TArray구간은 TChar 배열을 포함한 컨테이너로 포인터 값을 넘겨준면 반환값을 FString으로
	* 지정했기 때문에, 자동으로 FString이 만들어져서 반환된다.
	*/

	return RandArray.GetData(); // RandArray에 있는 GetData함수를 호출해서 자동으로 FString이 만들어지도록 처리
}



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



	/*300개의 TArray 구조체와 Map*/
	const int32 StudentNum = 300;
	for (int32 ix = 1; ix <= StudentNum; ++ix)
	{
		// 담을 수 있는 컨테이너를 헤더에 선언됨
		/*add()와 Emplace()가 있는데 구조체로 데이터를 집어 넣는 경우 복사비용이 조금 발생할 수 있기에
		* Emplace를 사용한다.
		* Emplace() : 복사 비용이 발생할 수 있는 곳에 사용
		*/
		StudentsData.Emplace(FStudentData(MakeRandomName(), ix));
	}

	// 이름들에 대한 TArray 구성
	TArray<FString> AllStudentsNames;

	Algo::Transform(StudentsData, AllStudentsNames,
		[](const FStudentData& Val) // 위 TArray에서 사용한 Value값을 첫번째 인자로 가져온다.
		{
			// 옮길 데이터 값에 대한 FString값을 return 값으로 준다.
			return Val.Name; // StudentData의 TArray를 StringTArray로 한번에 호출 가능
		}
	);


	UE_LOG(LogTemp, Log, TEXT("모든 학생 이름의 수 : %d"), AllStudentsNames.Num()); // 전체갯수를 찍는다.

	// 똑같이 Transform을 사용하지만 Set에 넣어보자.
	/*
	* Set은 중복허용을 하지않는다. : 변수명 : AllUniqueNames 선언
	*/

	TSet<FString> AllUniqueNames;
	Algo::Transform(StudentsData, AllUniqueNames,
		[](const FStudentData& Val)
		{
			return Val.Name;
		}
	);

	UE_LOG(LogTemp, Log, TEXT("중복 없는 학생 이름의 수 : %d"), AllUniqueNames.Num());


	/*TMap 사용*/
	// 기존 TArray로 선언된 것을 TMap으로 변환
	Algo::Transform(StudentsData, StudentsMap,
		[](const FStudentData& Val)
		{
			// Pair로 return을 해줘야 한다 해당 Pair를 맵과 똑같은 타입을 가진TPair를 선언 생성자로 Value의 Order와 Name을 집어넣어 Pair객체를 생성해서 반환
			// 위에서 대입해준 300개의 데이터가 들어간 맵이 완성된다.
			return TPair<int32, FString>(Val.Order, Val.Name);
		}
	);

	// Log
	UE_LOG(LogTemp, Log, TEXT("순번에 따른 학생 맵의 레코드 수 : %d"), StudentsMap.Num());

	// 이름을 키로해서 학생맵 TMap에 Fstring과 int32로 MapByName 이라고 자료구조 선언 일반 Map의 경우 중복을 허용하지 않기 때문에 UniqueName 명으로 선언
	TMap<FString, int32> StudentsMapByUniqueName;

	Algo::Transform(StudentsData, StudentsMapByUniqueName,
		[](const FStudentData& Val)
		{
			return TPair<FString, int32>(Val.Name, Val.Order);
		}
	);

	// 레코드가 몇 개인지 찍어볼 것이다 64개
	UE_LOG(LogTemp, Log, TEXT("이름에 따른 학생 맵의 레코드 수 : %d"), StudentsMapByUniqueName.Num());

	//만약 중복을 허용하고 싶다면 TMultiMap을 사용해서 선언해 주면 중복가능한 맵 자료구조가 만들어진다.

	TMultiMap<FString, int32> StudentMapByName;
	Algo::Transform(StudentsData, StudentMapByName,
		[](const FStudentData& Val)
		{
			return TPair<FString, int32>(Val.Name, Val.Order);
		}
	);

	UE_LOG(LogTemp, Log, TEXT("이름에 따른 학생 멀티맵의 레코드 수 : %d"), StudentMapByName.Num());


	/*어떤 이름을 가진 학생이 몇명인지*/
	const FString TargetName(TEXT("이혜은"));
	TArray<int32> AllOrders;
	StudentMapByName.MultiFind(TargetName, AllOrders);

	UE_LOG(LogTemp, Log, TEXT("이름이 %s인 학생 수 : %d"), *TargetName, AllOrders.Num());


	/*FStudentData를 TSet에서 사용*/
	TSet<FStudentData> StudentsSet;
	for (int32 ix = 1; ix <= StudentNum; ++ix)
	{
		StudentsSet.Emplace(FStudentData(MakeRandomName(), ix));
	}
}
