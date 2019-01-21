// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrollingRoute.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class S05_TESTINGGROUND_API UPatrollingRoute : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "TargetPoints")
	TArray<class AActor*> TargetPoints;

public:

	 TArray<class AActor*> GetTargetPoints() const;
		
	
};
