// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "partyGames_2025/Public/TurnManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTurnManager() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
PARTYGAMES_2025_API UClass* Z_Construct_UClass_ATurnManager();
PARTYGAMES_2025_API UClass* Z_Construct_UClass_ATurnManager_NoRegister();
UPackage* Z_Construct_UPackage__Script_partyGames_2025();
// End Cross Module References

// Begin Class ATurnManager
void ATurnManager::StaticRegisterNativesATurnManager()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATurnManager);
UClass* Z_Construct_UClass_ATurnManager_NoRegister()
{
	return ATurnManager::StaticClass();
}
struct Z_Construct_UClass_ATurnManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "TurnManager.h" },
		{ "ModuleRelativePath", "Public/TurnManager.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATurnManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ATurnManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_partyGames_2025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATurnManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATurnManager_Statics::ClassParams = {
	&ATurnManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATurnManager_Statics::Class_MetaDataParams), Z_Construct_UClass_ATurnManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATurnManager()
{
	if (!Z_Registration_Info_UClass_ATurnManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATurnManager.OuterSingleton, Z_Construct_UClass_ATurnManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATurnManager.OuterSingleton;
}
template<> PARTYGAMES_2025_API UClass* StaticClass<ATurnManager>()
{
	return ATurnManager::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATurnManager);
ATurnManager::~ATurnManager() {}
// End Class ATurnManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_partyGames_2025_Source_partyGames_2025_Public_TurnManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATurnManager, ATurnManager::StaticClass, TEXT("ATurnManager"), &Z_Registration_Info_UClass_ATurnManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATurnManager), 3811072552U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_partyGames_2025_Source_partyGames_2025_Public_TurnManager_h_1315896260(TEXT("/Script/partyGames_2025"),
	Z_CompiledInDeferFile_FID_partyGames_2025_Source_partyGames_2025_Public_TurnManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_partyGames_2025_Source_partyGames_2025_Public_TurnManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
