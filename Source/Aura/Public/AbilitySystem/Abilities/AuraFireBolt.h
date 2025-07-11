// Copyright Alex Walker'GD

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/AuraProjectilSpell.h"
#include "AuraFireBolt.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraFireBolt : public UAuraProjectilSpell
{
	GENERATED_BODY()

public:

	virtual FString GetDescription(int32 Level)override;
	virtual FString GetNextLevelDescription(int32 Level)override;

	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void SpawnProjectiles(const FVector& ProjectileTargetLocation, const FGameplayTag& SocketTag, bool bOverridePitch, float PitchOverride , AActor* HomingTarget);

	UPROPERTY(EditDefaultsOnly, Category="Firebolt")
	float ProjectileSpread = 90.f;

	UPROPERTY(EditDefaultsOnly, Category="Firebolt")
	int32 NumProjectiles = 5;

	UPROPERTY(EditDefaultsOnly, Category="Firebolt")
	float HomingAccelerationMin = 1600.f;

	UPROPERTY(EditDefaultsOnly, Category="Firebolt")
	float HomingAccelerationMax = 3200.f;

	UPROPERTY(EditDefaultsOnly, Category="Firebolt")
	bool bLaunchHomingProjectiles = true;
};
