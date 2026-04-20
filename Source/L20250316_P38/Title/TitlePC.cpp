// Fill out your copyright notice in the Description page of Project Settings.


#include "TitlePC.h"
#include "Kismet/KismetSystemLibrary.h"

void ATitlePC::BeginPlay()
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("PC::BeginPlay Pre"));

	Super::BeginPlay();

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("PC::BeginPlay Post"));

}
