// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "partyGames_2025/Public/PartyGameGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePartyGameGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
PARTYGAMES_2025_API UClass* Z_Construct_UClass_APartyGameGameMode();
PARTYGAMES_2025_API UClass* Z_Construct_UClass_APartyGameGameMode_NoRegister();
PARTYGAMES_2025_API UClass* Z_Construct_UClass_ATurnManager_NoRegister();
UPackage* Z_Construct_UPackage__Script_partyGames_2025();
// End Cross Module References

// Begin Class APartyGameGameMode
void APartyGameGameMode::StaticRegisterNativesAPartyGameGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APartyGameGameMode);
UClass* Z_Construct_UClass_APartyGameGameMode_NoRegister()
{
	return APartyGameGameMode::StaticClass();
}
struct Z_Construct_UClass_APartyGameGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "PartyGameGameMode.h" },
		{ "ModuleRelativePath", "Public/PartyGameGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TurnManager_MetaData[] = {
		{ "ModuleRelativePath", "Public/PartyGameGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TurnManager;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APartyGameGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APartyGameGameMode_Statics::NewProp_TurnManager = { "TurnManager", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APartyGameGameMode, TurnManager), Z_Construct_UClass_ATurnManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TurnManager_MetaData), NewProp_TurnManager_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APartyGameGameMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APartyGameGameMode_Statics::NewProp_TurnManager,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APartyGameGameMode_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_APartyGameGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_partyGames_2025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APartyGameGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APartyGameGameMode_Statics::ClassParams = {
	&APartyGameGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_APartyGameGameMode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_APartyGameGameMode_Statics::PropPointers),
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APartyGameGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_APartyGameGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APartyGameGameMode()
{
	if (!Z_Registration_Info_UClass_APartyGameGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APartyGameGameMode.OuterSingleton, Z_Construct_UClass_APartyGameGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APartyGameGameMode.OuterSingleton;
}
template<> PARTYGAMES_2025_API UClass* StaticClass<APartyGameGameMode>()
{
	return APartyGameGameMode::StaticClass();
}
APartyGameGameMode::APartyGameGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(APartyGameGameMode);
APartyGameGameMode::~APartyGameGameMode() {}
// End Class APartyGameGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_partyGames_2025_Source_partyGames_2025_Public_PartyGameGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APartyGameGameMode, APartyGameGameMode::StaticClass, TEXT("APartyGameGameMode"), &Z_Registration_Info_UClass_APartyGameGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APartyGameGameMode), 617086873U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_partyGames_2025_Source_partyGames_2025_Public_PartyGameGameMode_h_3024772164(TEXT("/Script/partyGames_2025"),
	Z_CompiledInDeferFile_FID_partyGames_2025_Source_partyGames_2025_Public_PartyGameGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_partyGames_2025_Source_partyGames_2025_Public_PartyGameGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
