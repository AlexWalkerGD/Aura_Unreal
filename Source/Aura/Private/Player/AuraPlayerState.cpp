// Copyright Alex Walker'GD


#include "Player/AuraPlayerState.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Net/UnrealNetwork.h"

AAuraPlayerState::AAuraPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
	
	NetUpdateFrequency = 100.f;
}

void AAuraPlayerState::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AAuraPlayerState, Level);
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAuraPlayerState::AddToXP(int32 InXP)
{
	XP += InXP;
	OnXPChangeDelegate.Broadcast(XP);	
}

void AAuraPlayerState::AddToLevel(int32 InLevel)
{
	Level += InLevel;
	OnLevelChangeDelegate.Broadcast(Level);
}

void AAuraPlayerState::SetXP(int32 InXP)
{
	XP = InXP;
	OnXPChangeDelegate.Broadcast(XP);
}

void AAuraPlayerState::SetLevel(int32 InLevel)
{
	Level = InLevel;
	OnLevelChangeDelegate.Broadcast(Level);
}

void AAuraPlayerState::OnRep_Level(int32 OldLevel)
{
	OnLevelChangeDelegate.Broadcast(Level);
}

void AAuraPlayerState::OnRep_XP(int32 OldXP)
{
	OnXPChangeDelegate.Broadcast(XP);
}
