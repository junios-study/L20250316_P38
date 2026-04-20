// Fill out your copyright notice in the Description page of Project Settings.


#include "HPBarBase.h"
#include "Components/ProgressBar.h"

void UHPBarBase::NativeConstruct()
{
	Super::NativeConstruct();
}

void UHPBarBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	
	//UE_LOG(LogTemp, Warning, TEXT("HPBar Owner : %s"), ->GetName());
}

void UHPBarBase::SetHPBar(float InPercent)
{
	if (HPBar)
	{
		HPBar->SetPercent(InPercent);
	}
}
