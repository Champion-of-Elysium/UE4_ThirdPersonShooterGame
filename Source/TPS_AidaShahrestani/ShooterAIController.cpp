// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"


void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();
}

void AShooterAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    FVector ViewPoint = FVector(ForceInit);

    if(LineOfSightTo(PlayerPawn))
    {
        MoveToActor(PlayerPawn, AcceptanceRadius);
        SetFocus(PlayerPawn);
    }
    else
    {
        ClearFocus(EAIFocusPriority::Gameplay);
        StopMovement();
    }
}
