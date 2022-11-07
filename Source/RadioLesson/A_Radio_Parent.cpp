// Fill out your copyright notice in the Description page of Project Settings.


#include "A_Radio_Parent.h"

// Sets default values
AA_Radio_Parent::AA_Radio_Parent()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	Scene->SetupAttachment(RootComponent);

	Mesh = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Scene);

	UStaticMesh* mesh= LoadObject<UStaticMesh>(nullptr, TEXT("/Game/StarterContent/Props/SM_Radio.SM_Radio"));
	/*static ConstructorHelpers::FObjectFinder<UStaticMesh> meshObject(TEXT("/Game/StarterContent/Props/SM_Radio.SM_Radio"));
	if (meshObject.Succeeded()) {

		mesh = meshObject.Object;
	}*/


	Mesh->SetStaticMesh(mesh);
	Mesh->SetSimulatePhysics(true);

	Audio = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	Audio->SetupAttachment(Mesh);


	
	SoundToPlay = CreateDefaultSubobject<USoundBase>(TEXT("Sound Play"));



}

void AA_Radio_Parent::turnOff_Implementation()
{
	Audio->SetPaused(true);
}



void AA_Radio_Parent::turnOn_Implementation()
{
	Audio->SetPaused(false);
}

// Called when the game starts or when spawned
void AA_Radio_Parent::BeginPlay()
{
	Super::BeginPlay();
	Audio->SetSound(SoundToPlay);


}

// Called every frame
void AA_Radio_Parent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

