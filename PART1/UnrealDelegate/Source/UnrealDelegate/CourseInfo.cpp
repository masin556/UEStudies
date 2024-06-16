// Fill out your copyright notice in the Description page of Project Settings.


#include "CourseInfo.h"

UCourseInfo::UCourseInfo()
{
	Contents = TEXT("기존 학사 정보");
}

void UCourseInfo::ChangeCourseInfo(const FString& InSchoolName, const FString& InNewContents)
{
	// 새로운 학사 정보가 들어오면 변경
	Contents = InNewContents;

	//발송 전 로그 [태그]사용
	UE_LOG(LogTemp, Log, TEXT("[CourseInfo] 학사 정보가 변경 되어 알림을 발송합니다."));
	//OnChanged에 연결된 모든 함수들에게 BroadCasting
	OnChanged.Broadcast(InSchoolName, Contents);
}
