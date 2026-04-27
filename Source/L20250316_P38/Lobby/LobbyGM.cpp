// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGM.h"
#include "LobbyGS.h"

//서버로직, 리슨 서버, 데디케이트 서버
void ALobbyGM::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(LeftTimeHandle,
		FTimerDelegate::CreateLambda([this]() {
			ALobbyGS* GS = GetGameState<ALobbyGS>();
			if (GS)
			{
				GS->LeftTime--;
			}
			}),
		1.0f,
		true,
		0.0f
	);
}

void ALobbyGM::StartPlay()
{
	Super::StartPlay();

	ALobbyGS* GS = GetGameState<ALobbyGS>();

	if (GS)
	{
		GS->ConnectionCount = GetNumPlayers();
		GS->OnRep_ConnectionCount();
	}
}


//서버만
void ALobbyGM::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	ALobbyGS* GS = GetGameState<ALobbyGS>();

	if (GS)
	{
		GS->ConnectionCount = GetNumPlayers();
		GS->OnRep_ConnectionCount();
	}
}

void ALobbyGM::StopTimer()
{
	GetWorldTimerManager().ClearTimer(LeftTimeHandle);
}
