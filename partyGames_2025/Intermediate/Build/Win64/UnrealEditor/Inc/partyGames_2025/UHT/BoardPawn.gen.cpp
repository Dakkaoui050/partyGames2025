// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "partyGames_2025/Public/BoardPawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoardPawn() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APawn();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
PARTYGAMES_2025_API UClass* Z_Construct_UClass_ABoardPawn();
PARTYGAMES_2025_API UClass* Z_Construct_UClass_ABoardPawn_NoRegister();
UPackage* Z_Construct_UPackage__Script_partyGames_2025();
// End Cross Module References

// Begin Class ABoardPawn
void ABoardPawn::StaticRegisterNativesABoardPawn()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABoardPawn);
UClass* Z_Construct_UClass_ABoardPawn_NoRegister()
{
	return ABoardPawn::StaticClass();
}
struct Z_Construct_UClass_ABoardPawn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "BoardPawn.h" },
		{ "ModuleRelativePath", "Public/BoardPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PawnMesh_MetaData[] = {
		{ "Category", "BoardPawn" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BoardPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveSpeed_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/BoardPawn.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PawnMesh;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MoveSpeed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABoardPawn>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoardPawn_Statics::NewProp_PawnMesh = { "PawnMesh", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoardPawn, PawnMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PawnMesh_MetaData), NewProp_PawnMesh_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoardPawn_Statics::NewProp_MoveSpeed = { "MoveSpeed", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoardPawn, MoveSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveSpeed_MetaData), NewProp_MoveSpeed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABoardPawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoardPawn_Statics::NewProp_PawnMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoardPawn_Statics::NewProp_MoveSpeed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABoardPawn_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABoardPawn_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APawn,
	(UObject* (*)())Z_Construct_UPackage__Script_partyGames_2025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABoardPawn_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABoardPawn_Statics::ClassParams = {
	&ABoardPawn::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ABoardPawn_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ABoardPawn_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoardPawn_Statics::Class_MetaDataParams), Z_Construct_UClass_ABoardPawn_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABoardPawn()
{
	if (!Z_Registration_Info_UClass_ABoardPawn.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABoardPawn.OuterSingleton, Z_Construct_UClass_ABoardPawn_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABoardPawn.OuterSingleton;
}
template<> PARTYGAMES_2025_API UClass* StaticClass<ABoardPawn>()
{
	return ABoardPawn::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABoardPawn);
ABoardPawn::~ABoardPawn() {}
// End Class ABoardPawn

// Begin Registration
struct Z_CompiledInDeferFile_FID_partyGames_2025_Source_partyGames_2025_Public_BoardPawn_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABoardPawn, ABoardPawn::StaticClass, TEXT("ABoardPawn"), &Z_Registration_Info_UClass_ABoardPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABoardPawn), 3533789781U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_partyGames_2025_Source_partyGames_2025_Public_BoardPawn_h_3758443159(TEXT("/Script/partyGames_2025"),
	Z_CompiledInDeferFile_FID_partyGames_2025_Source_partyGames_2025_Public_BoardPawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_partyGames_2025_Source_partyGames_2025_Public_BoardPawn_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
