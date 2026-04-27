// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LobbyPC.generated.h"

class ULobbyWidgetBase;
/**
 * 
 */
UCLASS()
class L20250316_P38_API ALobbyPC : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<ULobbyWidgetBase> LobbyWidgetTemplate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TObjectPtr<ULobbyWidgetBase> LobbyWidgetInstance;

	//Client -> Server(검증)
	UFUNCTION(Server, Reliable, WithValidation)
	void C2S_SendMessage(const FText& Message); //호출, client
	bool C2S_SendMessage_Validate(const FText& Message); //검증
	void C2S_SendMessage_Implementation(const FText& Message); //목적지에서 실행, Server


	UFUNCTION(Client, Unreliable)
	void S2C_SendMessage(const FText& Message);
	void S2C_SendMessage_Implementation(const FText& Message); //목적지에서 실행, Server

};
