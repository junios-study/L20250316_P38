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
		LobbyWidgetInstance->AddToViewport();

		if (LobbyWidgetInstance && HasAuthority())
		{
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

bool ALobbyPC::C2S_SendMessage_Validate(const FText& Message)
{ 
	return true;
	//return false; // 클라이언트 종료
}


void ALobbyPC::C2S_SendMessage_Implementation(const FText& Message)
{
	//모든 PC에 메세지 보냄
	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		ALobbyPC* PC = Cast<ALobbyPC>(Iterator->Get());
		if (PC)
		{
			PC->S2C_SendMessage(Message);
		}
	}
}

void ALobbyPC::S2C_SendMessage_Implementation(const FText& Message)
{
	if (LobbyWidgetInstance)
	{
		LobbyWidgetInstance->AddMessage(Message);
	}
}
