// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyWidgetBase.h"
#include "Components/Button.h"
#include "LobbyGS.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"
#include "Kismet/GameplayStatics.h"
#include "LobbyPC.h"

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
	switch (CommitMethod)
	{
		case ETextCommit::OnEnter:
		{
			ALobbyPC* PC = Cast<ALobbyPC>(GetOwningPlayer());

			if (PC)
			{
				//ID, Password, GameSubSystyem에서 아이디 가져와서 넣어주면 됨
				PC->C2S_SendMessage(Text);
				Inputbox->SetText(FText::GetEmpty());
			}
		}
		break;
		case ETextCommit::OnCleared:
		{
			Inputbox->SetUserFocus(GetOwningPlayer());
		}
	}
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


///서버에서 메세지 오면 추가한다.
void ULobbyWidgetBase::AddMessage(const FText& Message)
{
	if (ChatScrollBox)
	{
		UTextBlock* NewChat = NewObject<UTextBlock>(ChatScrollBox);
		if (NewChat)
		{
			NewChat->SetText(Message);
			FSlateFontInfo FontInfo = NewChat->GetFont();
			FontInfo.Size = 11;
			NewChat->SetFont(FontInfo);

			ChatScrollBox->AddChild(NewChat);
			ChatScrollBox->ScrollToEnd();
			//메모리 관리
			//일정 갯수가 되면 삭제 하는거 넣어야 됨
		}
	}
}
