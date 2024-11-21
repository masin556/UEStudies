// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 1. �Ϲ� C++ ������Ʈ�� F ���λ縦 �ٿ��ִ°� ����.
 * 2. �Ϲ� C++��ü�� ��۸� ������ ������ ����� �̰��� ���������� ������Ű�� ����
 *	- �𸮾� ������ �÷��Ϳ��� �Ϲ� C++��ü���� ���� �𸮾� ������Ʈ�� �����ϰڴ� �˷���� �Ѵ�. �̶� FGCObject ��� ���� ��ӹ޾� ����ؾ� �Ѵ�.
 *		- �̶� �ΰ��� �Լ��� �����ؾ� �Ѵ�. �߻� ������ AddReferencedObject , GetReferencerName�� ��������� �Ѵ�. 
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
