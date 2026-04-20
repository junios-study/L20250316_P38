// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_CheckDistance.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "ZombieAIController.h"

UBTTask_CheckDistance::UBTTask_CheckDistance()
{
	NodeName = TEXT("CheckDistance");
}

EBTNodeResult::Type UBTTask_CheckDistance::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AActor* Player = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(GetSelectedBlackboardKey()));

	if (Player)
	{
		AZombieAIController* ZombieAIC = Cast<AZombieAIController>(OwnerComp.GetAIOwner());
		AZombie* Zombie = Cast<AZombie>(OwnerComp.GetAIOwner()->GetPawn());
		FVector ZombieLocation = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();
		FVector PlayerLocation = Player->GetActorLocation();

		float Distance = FVector::Dist2D(ZombieLocation, PlayerLocation);

		switch (TargetCondition)
		{
			case ECondition::GraterThan:
			{
				if (Distance > TargetDistance)
				{
					ZombieAIC->SetState(TargetState);
				}
				break;
			}
			case ECondition::LessThan:
			{
				if (Distance < TargetDistance)
				{
					ZombieAIC->SetState(TargetState);
				}
				break;
			}
		}
	}

	return EBTNodeResult::Succeeded;
}
