// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Aura/Public/Game/AuraGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAuraGameMode() {}
// Cross Module References
	AURA_API UClass* Z_Construct_UClass_AAuraGameMode();
	AURA_API UClass* Z_Construct_UClass_AAuraGameMode_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Aura();
// End Cross Module References
	void AAuraGameMode::StaticRegisterNativesAAuraGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAuraGameMode);
	UClass* Z_Construct_UClass_AAuraGameMode_NoRegister()
	{
		return AAuraGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AAuraGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAuraGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Aura,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAuraGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAuraGameMode_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Game/AuraGameMode.h" },
		{ "ModuleRelativePath", "Public/Game/AuraGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAuraGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAuraGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AAuraGameMode_Statics::ClassParams = {
		&AAuraGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAuraGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AAuraGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AAuraGameMode()
	{
		if (!Z_Registration_Info_UClass_AAuraGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAuraGameMode.OuterSingleton, Z_Construct_UClass_AAuraGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AAuraGameMode.OuterSingleton;
	}
	template<> AURA_API UClass* StaticClass<AAuraGameMode>()
	{
		return AAuraGameMode::StaticClass();
	}
	AAuraGameMode::AAuraGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAuraGameMode);
	AAuraGameMode::~AAuraGameMode() {}
	struct Z_CompiledInDeferFile_FID_Users_alexw_Documents_Unreal_Projects_Aura_Source_Aura_Public_Game_AuraGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alexw_Documents_Unreal_Projects_Aura_Source_Aura_Public_Game_AuraGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AAuraGameMode, AAuraGameMode::StaticClass, TEXT("AAuraGameMode"), &Z_Registration_Info_UClass_AAuraGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAuraGameMode), 4163080657U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alexw_Documents_Unreal_Projects_Aura_Source_Aura_Public_Game_AuraGameMode_h_1454960648(TEXT("/Script/Aura"),
		Z_CompiledInDeferFile_FID_Users_alexw_Documents_Unreal_Projects_Aura_Source_Aura_Public_Game_AuraGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alexw_Documents_Unreal_Projects_Aura_Source_Aura_Public_Game_AuraGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
