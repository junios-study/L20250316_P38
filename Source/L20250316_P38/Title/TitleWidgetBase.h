// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleWidgetBase.generated.h"


class UButton;
class UEditableTextBox;
/**
 * 
 */
UCLASS()
class L20250316_P38_API UTitleWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void StartServer();

	UFUNCTION()
	void Connect();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(WidgetBind))
	TObjectPtr<UButton> ConnectButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (WidgetBind))
	TObjectPtr<UButton> StartServerButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (WidgetBind))
	TObjectPtr<UEditableTextBox> UserID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (WidgetBind))
	TObjectPtr<UEditableTextBox> Password;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (WidgetBind))
	TObjectPtr<UEditableTextBox> ServerIP;

	void SaveData();
};
