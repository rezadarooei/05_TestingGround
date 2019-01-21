// Fill out your copyright notice in the Description page of Project Settings.

#include "PatrollingRoute.h"


 TArray<class AActor*> UPatrollingRoute::GetTargetPoints() const
{
	return TargetPoints;
}
