// Fill out your copyright notice in the Description page of Project Settings.


#include "A_Radio_Child1.h"

void AA_Radio_Child1::BeginPlay() {

	AA_Radio_Parent::BeginPlay();
	Audio->Play(0);
	//turnOn();
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("BeginTurned!"));
}

