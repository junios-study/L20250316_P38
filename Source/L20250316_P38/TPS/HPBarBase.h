// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HPBarBase.generated.h"


class UProgressBar;
/**
 * 
 */
UCLASS()
class L20250316_P38_API UHPBarBase : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (WidgetBind))
	TObjectPtr<UProgressBar> HPBar;

};
