// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LobbyWidgetBase.generated.h"

class UScrollBox;
class UEditableTextBox;
class UTextBlock;
class UButton;

/**
 * 
 */
UCLASS()
class L20250316_P38_API ULobbyWidgetBase : public UUserWidget
{
	GENERATED_BODY()
public:

	virtual void NativeOnInitialized() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (BindWidget))
	TObjectPtr<UScrollBox> ChatScrollBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (BindWidget))
	TObjectPtr<UEditableTextBox> Inputbox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (BindWidget))
	TObjectPtr<UTextBlock> LeftTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (BindWidget))
	TObjectPtr<UTextBlock> ConnectionCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (BindWidget))
	TObjectPtr<UButton> SendButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (BindWidget))
	TObjectPtr<UButton> StartButton;

	UFUNCTION(BlueprintCallable)
	void ProcessCommited(const FText& Text, ETextCommit::Type CommitMethod);

	UFUNCTION(BlueprintCallable)
	void ProcessStart();

	UFUNCTION(BlueprintCallable)
	void ProcessSend();

	UFUNCTION()
	void Start();

	UFUNCTION(BlueprintCallable)
	void UpdateLeftTime(int32 InLeftTime);

	UFUNCTION(BlueprintCallable)
	void UpdateConnectionCount(int32 InConnectionCount);

	void ShowStartButton();

	void AddMessage(const FText& Message);
};

