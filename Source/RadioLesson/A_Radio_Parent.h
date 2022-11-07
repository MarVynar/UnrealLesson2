// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"
#include "A_Radio_Parent.generated.h"

UCLASS()
class RADIOLESSON_API AA_Radio_Parent : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AA_Radio_Parent();

	UFUNCTION(BlueprintNativeEvent)
		 void turnOff();

	UFUNCTION(BlueprintNativeEvent)
		 void turnOn();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		USceneComponent* Scene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		UAudioComponent* Audio;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		USoundBase* SoundToPlay;




public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
