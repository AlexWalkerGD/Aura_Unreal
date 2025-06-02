// Copyright Alex Walker'GD

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interact/PlayerInterface.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase, public IPlayerInterface
{
	GENERATED_BODY()

public:
	
	AAuraCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	//Combat Interface
	virtual int32 GetPlayerLevel() override;
	
	//Player Interface
	virtual void AddToXp_Implementation(int32 InXp) override;
	
private:
	virtual void InitAbilityActorInfo() override;
};
