// Fill out your copyright notice in the Description page of Project Settings.


#include "A_Radio_Child2.h"


AA_Radio_Child2::AA_Radio_Child2() :AA_Radio_Parent() {

	//PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(Scene);
	BoxCollision->SetBoxExtent(FVector(200.0f, 200.0f, 200.0f));
	

}

void AA_Radio_Child2::OnOverlapBegin(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int otherBodyIndex, bool fromSweep, const FHitResult& sweepResult)
{
	if (otherActor == GetWorld()->GetFirstPlayerController()->GetPawn()) {

		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("overbegin"));
		turnOn();
	}
}

void AA_Radio_Child2::OnOverlapEnd(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int otherBodyIndex)
{
	if (otherActor == GetWorld()->GetFirstPlayerController()->GetPawn()) {

		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("outend"));
		turnOff();
	}

}

void AA_Radio_Child2::BeginPlay()
{
	AA_Radio_Parent::BeginPlay();

	Audio->Play(0);
	turnOff();
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AA_Radio_Child2::OnOverlapBegin);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &AA_Radio_Child2::OnOverlapEnd);
}

/*
void AA_Radio_Child2::turnOff()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("OverOff"));
	Audio->SetVolumeMultiplier(0);
}

*/
void AA_Radio_Child2::turnOn()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("OverOn"));
	Audio->SetVolumeMultiplier(1);
}


