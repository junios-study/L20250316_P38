// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "LobbyGS.generated.h"

/**
 * 
 */
UCLASS()
class L20250316_P38_API ALobbyGS : public AGameStateBase
{
	GENERATED_BODY()

public:
	//서버에서 바꾼다. 클라이언트 뷰어(동영상 플레이어)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data", Replicated)
	int32 LeftTime = 60;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data", ReplicatedUsing="OnRep_ConnectionCount")
	int32 ConnectionCount = 0;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/// <summary>
	/// BP 서버랑 클라이언트 다 호출, C++ 서버 호출(안됨), client 호출
	/// </summary>
	UFUNCTION()
	void OnRep_ConnectionCount();
};
