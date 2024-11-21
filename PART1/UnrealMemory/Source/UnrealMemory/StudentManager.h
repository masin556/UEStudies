// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 1. 일반 C++ 오브젝트는 F 접두사를 붙여주는게 좋다.
 * 2. 일반 C++객체는 댕글링 포인터 문제가 생긴다 이것을 안정적으로 유지시키기 위해
 *	- 언리얼 가비지 컬렉터에게 일반 C++객체에가 나는 언리얼 오브젝트를 관리하겠다 알려줘야 한다. 이때 FGCObject 라는 것을 상속받아 사용해야 한다.
 *		- 이때 두가지 함수를 구현해야 한다. 추상 형태인 AddReferencedObject , GetReferencerName을 구현해줘야 한다. 
 */

class UNREALMEMORY_API FStudentManager : public FGCObject
{
public:
	FStudentManager(class UStudent* InStudent) : SafeStudent(InStudent) {}

	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

	virtual FString GetReferencerName() const override
	{
		return TEXT("FStudentManager");
	}

	const class UStudent* GetStudent() const { return SafeStudent; }

 private:
	class UStudent* SafeStudent = nullptr;

};
