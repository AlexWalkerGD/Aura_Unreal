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

	UPROPERTY()
	float ProjectileSpread = 90.f;

	UPROPERTY()
	int32 NumProjectiles = 5;
};
