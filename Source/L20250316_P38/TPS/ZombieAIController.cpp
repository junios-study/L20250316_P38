// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieAIController.h"

AZombieAIController::AZombieAIController()
{
}

void AZombieAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (RunBTAsset)
	{
		RunBehaviorTree(RunBTAsset);
	}
}

void AZombieAIController::OnUnPossess()
{
	Super::OnUnPossess();
}
