// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyWidgetBase.h"
#include "Components/Button.h"
#include "LobbyGS.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"
#include "Kismet/GameplayStatics.h"

void ULobbyWidgetBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (StartButton)
	{
		StartButton->OnClicked.AddDynamic(this, &ULobbyWidgetBase::ProcessStart);
	}

	if (SendButton)
	{
		SendButton->OnClicked.AddDynamic(this, &ULobbyWidgetBase::ProcessSend);
	}

	if (Inputbox)
	{
		Inputbox->OnTextCommitted.AddDynamic(this, &ULobbyWidgetBase::ProcessCommited);
	}

	ALobbyGS* GS = Cast<ALobbyGS>(UGameplayStatics::GetGameState(GetWorld()));
	if (GS)
	{
		GS->OnChangeConnectionCount.AddDynamic(this, &ULobbyWidgetBase::UpdateConnectionCount);
	}
}

void ULobbyWidgetBase::ProcessCommited(const FText& Text, ETextCommit::Type CommitMethod)
{
}

void ULobbyWidgetBase::ProcessStart()
{
}

void ULobbyWidgetBase::ProcessSend()
{
}

void ULobbyWidgetBase::Start()
{
}


void ULobbyWidgetBase::UpdateLeftTime(int32 InLeftTime)
{
	FString Temp = FString::Printf(TEXT("%d초 남음"), InLeftTime);
	LeftTime->SetText(FText::FromString(Temp));
}

void ULobbyWidgetBase::UpdateConnectionCount(int32 InConnectionCount)
{
	FString Temp = FString::Printf(TEXT("%d명 접속"), InConnectionCount);
	ConnectionCount->SetText(FText::FromString(Temp));
}

void ULobbyWidgetBase::ShowStartButton()
{
	if (StartButton)
	{
		StartButton->SetVisibility(ESlateVisibility::Visible);
	}
}
