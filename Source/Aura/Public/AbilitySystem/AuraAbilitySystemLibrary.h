// Copyright Alex Walker'GD

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AuraAbilitySystemLibrary.generated.h"

class UAbilityInfo;
class USpellMenuWidgetController;
class UAbilitySystemComponent;
class UAttributeMenuWidgetController;
class UOverlayWidgetController;
/**
 * 
 */
UCLASS()
class AURA_API UAuraAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category = "AbilitySystem|WidgetController", meta = (DefaultToSelf = "WorldContextObject"))
	static UOverlayWidgetController* GetOverlayWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category = "AbilitySystem|WidgetController", meta = (DefaultToSelf = "WorldContextObject"))
	static UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const UObject* WorldContextObject);
	
	UFUNCTION(BlueprintPure, Category = "AbilitySystem|WidgetController", meta = (DefaultToSelf = "WorldContextObject"))
	static USpellMenuWidgetController* GetSpellMenuWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "AbilitySystem|CharacterClassDefaults")
	static void InitializeDefaultAttributes(const UObject* WorldContextObject, ECharacterClass CharacterClass, float Level, UAbilitySystemComponent* ASC);

	UFUNCTION(BlueprintCallable, Category = "AbilitySystem|CharacterClassDefaults")
	static void GiveStartupAbilities(const UObject* WorldContextObject, UAbilitySystemComponent* ASC, ECharacterClass CharacterClass);

	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemLibrary|CharacterClassDefaults")
	static UCharacterClassInfo* GetCharacterClassInfo(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemLibrary|AbilityInfo")
	static UAbilityInfo* GetAbilityInfo(const UObject* WorldContextObject);
	
	UFUNCTION(BlueprintPure, Category = "AbilitySystem|GameplayEffects")
	static bool IsBlockedHit(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category = "AbilitySystem|GameplayEffects")
	static bool IsCriticalHit(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category = "AbilitySystem|GameplayEffects")
	static bool IsSuccessfulDebuff(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category = "AbilitySystem|GameplayEffects")
	static float GetDebuffDamage(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category = "AbilitySystem|GameplayEffects")
	static float GetDebuffDuration(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category = "AbilitySystem|GameplayEffects")
	static float GetDebuffFrequency(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category = "AbilitySystem|GameplayEffects")
	static FGameplayTag GetDamageType(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintCallable, Category = "AbilitySystem|GameplayEffects")
	static void SetIsBlockedHit(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle, bool bInIsBlockedHit);

	UFUNCTION(BlueprintCallable, Category = "AbilitySystem|GameplayEffects")
	static void SetIsCriticalHit(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle, bool bInIsCriticalHit);

	UFUNCTION(BlueprintCallable, Category = "AbilitySystem|GameplayEffects")
	static void SetIsSuccessfulDebuff(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle, bool bInSuccessfulDebuff);

	UFUNCTION(BlueprintCallable, Category = "AbilitySystem|GameplayEffects")
	static void SetDebuffDamage(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle, float InDamage);

	UFUNCTION(BlueprintCallable, Category = "AbilitySystem|GameplayEffects")
	static void SetDebuffDuration(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle, float InDuration);

	UFUNCTION(BlueprintCallable, Category = "AbilitySystem|GameplayEffects")
	static void SetDebuffFrequency(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle, float InFrequency);

	UFUNCTION(BlueprintCallable, Category = "AbilitySystem|GameplayEffects")
	static void SetDamageType(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle, const FGameplayTag& InDamageType);
	
	UFUNCTION(BlueprintCallable, Category = "AbilitySystem|GameplayMechanics")
	static void GetLivePlayersWithinRadius(const UObject* WorldContextObject, TArray<AActor*>& OutOverlappingActors, const TArray<AActor*>& ActorsToIgnore, float Radius, const FVector& SphereOrigin);

	UFUNCTION(BlueprintCallable, Category = "AbilitySystem|GameplayMechanics")
	static void GetClosestTargets(int32 MaxTargets, const TArray<AActor*>& Actors, TArray<AActor*>& OutClosestTargets, const FVector& Origin);
	
	UFUNCTION(BlueprintPure, Category = "AbilitySystem|GameplayMechanics")
	static bool IsNotFriend(AActor* FirstActor, AActor* SecondActor);

	UFUNCTION(BlueprintCallable, Category = "AbilitySystem|DamageEffect")
	static FGameplayEffectContextHandle ApplyDamageEffect(const FDamageEffectParams& DamageEffectParams);

	UFUNCTION(BlueprintCallable, Category = "AbilitySystem|GameplayMechanics")
	static TArray<FRotator> EventlySpacedRotators(const FVector& Forward, const FVector& Axis, float Spread, int32 NumRotators);

	UFUNCTION(BlueprintCallable, Category = "AbilitySystem|GameplayMechanics")
	static TArray<FVector> EventlyRotatedVectors(const FVector& Forward, const FVector& Axis, float Spread, int32 NumVectors);	

	static int32 GetXPRewardForClassAndLevel(const UObject* WorldContextObject, ECharacterClass CharacterClass, int32 CharacterLevel);
};


