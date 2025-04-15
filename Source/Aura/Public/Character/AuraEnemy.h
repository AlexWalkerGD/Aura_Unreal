// Copyright Alex Walker'GD

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interact/EnemyInterface.h"
#include "GameplayTagContainer.h"
#include "AbilitySystem/Data/CharacterClassInfo.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "AuraEnemy.generated.h"

class UWidgetComponent;
/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	
	AAuraEnemy();
	
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	virtual void InitializeDefaultAttributes() const override;

	virtual int32 GetPlayerLevel() override;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxHealthChanged;

	void HitReactTagChanged(const FGameplayTag Callbacktag, int32 NewCount);

	UPROPERTY(BlueprintReadOnly, Category= "Combat")
	bool bHitReacting = false;

	UPROPERTY(BlueprintReadOnly, Category= "Combat")
	float BaseWalkSpeed = 250.f;

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category= "Character Class Defaults")
	int32 Level = 1;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category= "Character Class Defaults")
	ECharacterClass CharacterClass = ECharacterClass::Warrior;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;
};
