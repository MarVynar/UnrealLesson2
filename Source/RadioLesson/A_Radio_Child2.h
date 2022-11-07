// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "A_Radio_Parent.h"
#include "A_Radio_Child2.generated.h"

/**
 * 
 */
UCLASS()
class RADIOLESSON_API AA_Radio_Child2 : public AA_Radio_Parent
{
	GENERATED_BODY()

		AA_Radio_Child2();

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int otherBodyIndex, bool fromSweep, const FHitResult& sweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int otherBodyIndex);

protected:

	void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		UBoxComponent* BoxCollision;

public:
		
		// void turnOff() ;
		 	
		 void turnOn() ;

};