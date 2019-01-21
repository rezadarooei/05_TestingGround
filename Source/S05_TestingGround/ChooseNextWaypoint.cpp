// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "AIController.h"
#include "PatrollingRoute.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto AICharcter = OwnerComp.GetAIOwner()->GetPawn();

	auto PatrollingRoute = AICharcter->FindComponentByClass<UPatrollingRoute>();
	if (!PatrollingRoute) { return EBTNodeResult::Failed; }

	
	TArray<AActor*> PatrolingPoints = PatrollingRoute->GetTargetPoints();

	if (PatrolingPoints.Num() == 0) {
		UE_LOG(LogTemp,Warning,TEXT("There is no pointing Route"))
	}
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	
	
	int32 TargetingPointLength = PatrolingPoints.Num();
	
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolingPoints[Index]);
	
	int32 mod =(Index+1) % TargetingPointLength;
	
	

	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, mod);
	UE_LOG(LogTemp,Warning,TEXT("Waypoint Index: %i"),Index)
	return EBTNodeResult::Succeeded;
}
