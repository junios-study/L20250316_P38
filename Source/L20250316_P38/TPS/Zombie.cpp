// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombie.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/WidgetComponent.h"
#include "HPBarBase.h"
#include "ZombieAIController.h"


// Sets default values
AZombie::AZombie()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->SetRelativeLocationAndRotation(
		FVector(0, 0, -GetCapsuleComponent()->GetScaledCapsuleHalfHeight()),
		FRotator(0, -90.0f, 0)
	);
}

// Called when the game starts or when spawned
void AZombie::BeginPlay()
{
	Super::BeginPlay();

	UWidgetComponent* Widget = Cast<UWidgetComponent>(GetComponentByClass(UWidgetComponent::StaticClass()));

	UHPBarBase* HPBar = Cast<UHPBarBase>(Widget->GetWidget());
	if (Widget && HPBar)
	{
		UE_LOG(LogTemp, Warning, TEXT("HP Bar Delegate bind"));
		OnChangeHPBar.AddDynamic(HPBar, &UHPBarBase::SetHPBar);
	}
	
}

// Called every frame
void AZombie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AZombie::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AZombie::SetMaxSpeed(float NewMaxSpeed)
{
	GetCharacterMovement()->MaxWalkSpeed = NewMaxSpeed;
}

float AZombie::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float Damage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	HP -= DamageAmount;

	UE_LOG(LogTemp, Warning, TEXT("HP %d"), HP);

	if (HP <= 0)
	{
		AZombieAIController* ZombieAIC = Cast<AZombieAIController>(GetController());
		if (ZombieAIC)
		{
			ZombieAIC->SetState(EZombieState::Death);
			CurrentState = EZombieState::Death;
			SetMaxSpeed(0);
			GetCharacterMovement()->SetMovementMode(
				EMovementMode::MOVE_None
			);
		}
	}

	HP = FMath::Clamp(HP, 0, 100);

	float Percent = (float)HP / (float)MaxHP;

	Percent = FMath::Clamp(Percent, 0, 1.f);


	OnChangeHPBar.Broadcast(Percent);

	return DamageAmount;
}



