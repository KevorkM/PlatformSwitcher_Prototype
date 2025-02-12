// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObstacleController.generated.h"

UCLASS()
class PLATFORMSWITCHER_API AObstacleController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacleController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		UShapeComponent*RootBox;

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent*OverlappedComponent, AActor*OtherActor, UPrimitiveComponent*OtherComponent, int32 OtherBodyIndex, bool BFromSweep, const FHitResult& SweepResult);
};
