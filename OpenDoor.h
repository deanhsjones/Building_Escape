//  Copyright Dean Jones 2021 all rights reversed

#pragma once

#include "CoreMinimal.h"
#include "Components/AudioComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	float TotalMassofActors() const;
	void FindPressurePlate();
	void FindAudioComponent();

	//tracks if sound was played
	bool SoundPlayedClosed = true;
	bool SoundPlayedOpen = true;
	

private:

float InitialYaw;
float CurrentYaw;

UPROPERTY(EditAnywhere)
float MassToOpenDoors = 50.f;

UPROPERTY(EditAnywhere)
float OpenAngle = 90.f;

UPROPERTY(EditAnywhere)
float DoorCloseDelay = 0.4f;

float DoorLastOpened = 0.f;

UPROPERTY(EditAnywhere)
float DoorOpenSpeed = 0.8f;

UPROPERTY(EditAnywhere)
float DoorCloseSpeed = 3.f;

UPROPERTY(EditAnywhere)
ATriggerVolume* PressurePlate = nullptr;

//UProperty()
UAudioComponent* AudioComponent = nullptr;

};
