// Fill out your copyright notice in the Description page of Project Settings.


#include "HPBarBase.h"
#include "Components/ProgressBar.h"

void UHPBarBase::NativeConstruct()
{
	Super::NativeConstruct();

	HPBar->SetPercent(1.0f);
}
