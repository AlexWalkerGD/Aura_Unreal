// Copyright Alex Walker'GD

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAuraEffectActor();

protected:
	virtual void BeginPlay() override;


	void ApplyEffectToTarget(AActor* target, TSubclassOf<UGameplayEffect> GamePlayEffectClass);
	
	UPROPERTY(EditAnywhere, Category= "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
	
};
