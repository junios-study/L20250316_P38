// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UArrowComponent;
class UCameraComponent;
class USpringArmComponent;
class UFloatingPawnMovement;


UCLASS()
class L20250316_P38_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	TObjectPtr<UBoxComponent> Box;

	TObjectPtr<UStaticMeshComponent> Body;

	TObjectPtr<UStaticMeshComponent> Left;

	TObjectPtr<UStaticMeshComponent> Right;

	TObjectPtr<USpringArmComponent> SpringArm;

	TObjectPtr<UCameraComponent>  Camera;

	TObjectPtr<UArrowComponent> Arrow;

	TObjectPtr<UFloatingPawnMovement> Movement;
};

