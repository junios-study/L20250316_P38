// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleWidgetBase.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Kismet/GameplayStatics.h"
#include "../DataGameInstanceSubsystem.h"

void UTitleWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();

	//Widget Blueprint와 C++ 컨트롤 변수와 연결

	if (StartServerButton)
	{
		StartServerButton->OnClicked.AddDynamic(this, &UTitleWidgetBase::StartServer);
	}

	if (ConnectButton)
	{
		ConnectButton->OnClicked.AddDynamic(this, &UTitleWidgetBase::Connect);
	}
}


void UTitleWidgetBase::StartServer()
{
	SaveData();
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("Lobby"), true, TEXT("listen"));
}

void UTitleWidgetBase::Connect()
{
	if (ServerIP)
	{
		SaveData();
		UGameplayStatics::OpenLevel(GetWorld(), *ServerIP->GetText().ToString(), true);
	}

}


void UTitleWidgetBase::SaveData()
{
	UGameInstance* GI = UGameplayStatics::GetGameInstance(GetWorld());
	if (GI)
	{
		UDataGameInstanceSubsystem* SubSystsem = GI->GetSubsystem<UDataGameInstanceSubsystem>();
		if (SubSystsem)
		{
			SubSystsem->UserID = UserID->GetText().ToString();
			SubSystsem->Password = Password->GetText().ToString();
		}
	}
}