// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMyActor::Move()
{
	start.X += Step();
	start.Y += Step();

	UE_LOG(LogTemp, Display, TEXT("플레이어가 이동했습니다. 현재 좌표 X: %f, Y: %f"), start.X, start.Y);
}

int AMyActor::Step()
{
	int rand = FMath::RandRange(0, 1);
	return rand;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	start = FVector2D(0, 0);
	for (int i = 0; i < 10; i++) {
		Move();
	}
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

