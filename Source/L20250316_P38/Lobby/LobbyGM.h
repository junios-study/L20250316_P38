// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LobbyGM.generated.h"

/**
 * 
 */
UCLASS()
class L20250316_P38_API ALobbyGM : public AGameModeBase
{
	GENERATED_BODY()
public:

	virtual void BeginPlay() override;

	virtual void StartPlay() override;


	virtual void PostLogin(APlayerController* NewPlayer) override;

	FTimerHandle LeftTimeHandle;

	void StopTimer();

};
