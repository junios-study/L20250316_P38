// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleGM.h"
#include "Kismet/KismetSystemLibrary.h"

void ATitleGM::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("PreLogin Pre"));

	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("PreLogin Post"));
}

APlayerController* ATitleGM::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Login Pre"));

	APlayerController* PC = Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Login Post"));

	return PC;
}

void ATitleGM::PostLogin(APlayerController* NewPlayer)
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("PostLogin Pre"));

	Super::PostLogin(NewPlayer);

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("PostLogin Post"));

}

void ATitleGM::StartPlay()
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("StartPlay Pre"));

	Super::StartPlay();

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("StartPlay Post"));

}
