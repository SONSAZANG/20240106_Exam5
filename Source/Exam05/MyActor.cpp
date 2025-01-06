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
	FVector2D preVec = start;
	start.X += Step();
	start.Y += Step();

	float distance = GetDistance(start, preVec);
	UE_LOG(LogTemp, Display, TEXT("플레이어가 이동했습니다. 현재 좌표 X: %f, Y: %f, 이동한 거리는: %f"), start.X, start.Y, distance);
	CreateEvent();
}

int AMyActor::Step()
{
	int rand = FMath::RandRange(0, 1);
	return rand;
}

float AMyActor::GetDistance(FVector2D first, FVector2D second)
{
	float distance = sqrt(pow((first.X - second.X), 2) + pow((first.Y - second.Y), 2));
	return distance;
}

void AMyActor::CreateEvent()
{
	int RandomValue = FMath::RandRange(1, 100);
	if (RandomValue <= 50) {
		UE_LOG(LogTemp, Display, TEXT("이벤트 발생!!!!"));
		eventCount++;
	}
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	eventCount = 0;
	start = FVector2D(0, 0);
	for (int i = 0; i < 10; i++) {
		Move();
	}
	
	float finalDistance = GetDistance(start, {0, 0});
	UE_LOG(LogTemp, Display, TEXT("10회 이동을 완료 했습니다. 총 이동거리: %f, 총 이벤트 발생횟수: %d"), finalDistance, eventCount);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

