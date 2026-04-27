// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPC.h"
#include "LobbyWidgetBase.h"
#include "Kismet/GameplayStatics.h"
#include "LobbyGS.h"

void ALobbyPC::BeginPlay()
{
	Super::BeginPlay();

	if (LobbyWidgetTemplate && IsLocalPlayerController())
	{
		LobbyWidgetInstance = CreateWidget<ULobbyWidgetBase>(this, LobbyWidgetTemplate);

		if (LobbyWidgetInstance && HasAuthority())
		{
			LobbyWidgetInstance->AddToViewport();
			LobbyWidgetInstance->ShowStartButton();
		}

		bShowMouseCursor = true;
		SetInputMode(FInputModeGameAndUI());
	}
}

void ALobbyPC::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	ALobbyGS* GS = Cast<ALobbyGS>(UGameplayStatics::GetGameState(GetWorld()));

	if (LobbyWidgetInstance && GS)
	{
		LobbyWidgetInstance->UpdateLeftTime(GS->LeftTime);
	}
}
