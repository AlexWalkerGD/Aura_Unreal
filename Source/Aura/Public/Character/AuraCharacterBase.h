// Copyright Alex Walker'GD

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffect.h"
#include "GameFramework/Character.h"
#include "Interact/CombatInterface.h"
#include "AbilitySystem/Data/CharacterClassInfo.h"
#include "AbilitySystem/Passive/PassiveNiagaraComponent.h"
#include "AuraCharacterBase.generated.h"

class UNiagaraSystem;
class UDebuffNiagaraComponent;
class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;
class UGameplayAbility;
class UAnimMontage;

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	
	AAuraCharacterBase();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

	UFUNCTION(NetMulticast,Reliable)
	virtual void MulticastHandleDeath();


	UPROPERTY(EditAnywhere, Category = "Combat")
	TArray<FTaggedMontage>AttackMontages;
	
	// Combat Interface
	
	virtual FVector GetCombatSocketLocation_Implementation(const FGameplayTag& MontageTag) override;
	virtual bool IsDead_Implementation() const override;
	virtual AActor* GetAvatar_Implementation() override;
	virtual void Die() override;
	virtual UAnimMontage* GetHitReactMontage_Implementation() override;
	virtual TArray<FTaggedMontage> GetAttackMontages_Implementation() override;
	virtual UNiagaraSystem* GetBloodEffect_Implementation() override;
	virtual FTaggedMontage GetTaggedMontageByTag_Implementation(const FGameplayTag& MontageTag) override;
	virtual int32 GetMinionCount_Implementation() override;
	virtual void IncrementMinionCount_Implementation(int32 Amount) override;
	virtual ECharacterClass GetCharacterClass_Implementation() override;
	virtual FOnASCRegistered GetOnASCRegisteredDelegate() override;
	virtual FOnDeath GetOnDeathDelegate() override;
	virtual USkeletalMeshComponent* GetWeapon_Implementation() override;
	void SetIsBeingShocked_Implementation(bool bInShock) override;
	bool IsBeingShocked_Implementation() const override;

	FOnASCRegistered OnAscRegistered;
	FOnDeath OnDeath;

	UPROPERTY(Replicated,BlueprintReadOnly)
	bool bIsBeingShocked = false;
	

protected:
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;

	bool bDead = false;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category= "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY(EditAnywhere, Category= "Combat")
	FName WeaponTipSocketName;

	UPROPERTY(EditAnywhere, Category= "Combat")
	FName RightHandSocketName;

	UPROPERTY(EditAnywhere, Category= "Combat")
	FName LeftHandSocketName;
	
	UPROPERTY(EditAnywhere, Category= "Combat")
	FName TailSocketName;
	
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	virtual void InitAbilityActorInfo();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Attributes")
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Attributes")
	TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Attributes")
	TSubclassOf<UGameplayEffect> DefaultVitalAttributes;

	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameEffectClass, float Level) const;
	virtual void InitializeDefaultAttributes() const;
	void AddCharacterAbilities();

	int32 MinionsCount = 0;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category= "Character Class Defaults")
	ECharacterClass CharacterClass = ECharacterClass::Warrior;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UDebuffNiagaraComponent> BurnDebuffComponent;
	
	// Dissolve Effects
	
	void Dissolve();

	UFUNCTION(BlueprintImplementableEvent)
	void StartDissolveTimeline(UMaterialInstanceDynamic* DynamicMaterialInstance);

	UFUNCTION(BlueprintImplementableEvent)
	void WeaponDissolveTimeline(UMaterialInstanceDynamic* DynamicMaterialInstance);

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TObjectPtr<UMaterialInstance>DissolveMaterialInstance;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TObjectPtr<UMaterialInstance>WeaponDissolveMaterialInstance;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Combat")
	UNiagaraSystem* BloodEffect;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Combat")
	USoundBase* DeathSound;

private:

	UPROPERTY(EditAnywhere, Category="Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

	UPROPERTY(EditAnywhere, Category="Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupPassiveAbilities;

	UPROPERTY(EditAnywhere, Category="Combat")
	TObjectPtr<UAnimMontage> HitReactMontage;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UPassiveNiagaraComponent> HaloOfProtectionNiagaraComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UPassiveNiagaraComponent> LifeSiphonNiagaraComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UPassiveNiagaraComponent> ManaSiphonNiagaraComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USceneComponent> EffectAttachComponent;
	
	
};



