//  Copyright Dean Jones 2021 all rights reversed

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	float Reach = 250.f;

	//UProperty()
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	//UProperty()
	UInputComponent* InputComponent = nullptr;

	void Grab();
	void Release();
	void FindPhysicsHandle();
	void SetupInputComponent();

	//return first actor within reach with phycis body
	FHitResult GetFirstPhysicsBodyInReach() const;

	//return linetraceend
	FVector GetPlayerReach() const;

	//get player position in world
	FVector GetPlayerWorldPos() const;

};
