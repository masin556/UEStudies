// Fill out your copyright notice in the Description page of Project Settings.


#include "Person.h"
#include "Card.h"

UPerson::UPerson()
{
	Name = TEXT("홍길동");
	//CDO에서 구현시 CreateDefaultSubobject 라는 API를 사용
	Card = CreateDefaultSubobject<UCard>(TEXT("NAME_Card")); //String이 아닌 FName이구나 알리기 위해 접두사로 NAME_을 붙여준다.

}

