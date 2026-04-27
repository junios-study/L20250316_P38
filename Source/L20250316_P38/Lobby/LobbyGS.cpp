// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGS.h"
#include "Net/UnrealNetwork.h"

void ALobbyGS::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ALobbyGS, LeftTime);
	DOREPLIFETIME(ALobbyGS, ConnectionCount);
}

//서버 값이 바뀌었을때 client에서 자동 호출, 단 서버에서 호출 안됨
void ALobbyGS::OnRep_ConnectionCount()
{
	OnChangeConnectionCount.Broadcast(ConnectionCount);
}
