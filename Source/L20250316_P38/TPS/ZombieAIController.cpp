// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AZombieAIController::AZombieAIController()
{
	Perception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception"));

	UAISenseConfig_Sight* Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight"));
	Sight->SightRadius = 800.0f;
	Sight->LoseSightRadius = 600.0f;
	Sight->PeripheralVisionAngleDegrees = 45.f;
	Sight->DetectionByAffiliation.bDetectEnemies = true;
	Sight->DetectionByAffiliation.bDetectFriendlies = false;
	Sight->DetectionByAffiliation.bDetectNeutrals = false;

	Perception->ConfigureSense(*Sight);
	Perception->SetDominantSense(*Sight->GetSenseImplementation());
}

void AZombieAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (RunBTAsset)
	{
		RunBehaviorTree(RunBTAsset);
	}

	SetGenericTeamId(7);

	Perception->OnTargetPerceptionUpdated.AddDynamic(this, &AZombieAIController::ProcessTargetUpdated);

	Perception->OnTargetPerceptionForgotten.AddDynamic(this, &AZombieAIController::ProcessTargetForgotten);
}

void AZombieAIController::OnUnPossess()
{
	Super::OnUnPossess();
}

void AZombieAIController::ProcessTargetUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	UE_LOG(LogTemp, Warning, TEXT("Perception %s"), *Actor->GetName());
}

void AZombieAIController::ProcessTargetForgotten(AActor* Actor)
{
	UE_LOG(LogTemp, Warning, TEXT("Forgotten %s"), *Actor->GetName());
}
