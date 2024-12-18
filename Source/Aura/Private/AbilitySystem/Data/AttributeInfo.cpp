// Copyright Alex Walker'GD


#include "AbilitySystem/Data/AttributeInfo.h"

#include "Misc/LowLevelTestAdapter.h"
#include "Misc/TrackedActivity.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for (const FAuraAttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(AttributeTag))
		{
			return Info;
		}
	}

	if (bLogNotFound)
	{
		
	}

	return FAuraAttributeInfo();
}
