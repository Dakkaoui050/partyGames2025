// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "partyGames_2025/Public/DiceActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDiceActor() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UArrowComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
PARTYGAMES_2025_API UClass* Z_Construct_UClass_ADiceActor();
PARTYGAMES_2025_API UClass* Z_Construct_UClass_ADiceActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_partyGames_2025();
// End Cross Module References

// Begin Class ADiceActor
void ADiceActor::StaticRegisterNativesADiceActor()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADiceActor);
UClass* Z_Construct_UClass_ADiceActor_NoRegister()
{
	return ADiceActor::StaticClass();
}
struct Z_Construct_UClass_ADiceActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DiceActor.h" },
		{ "ModuleRelativePath", "Public/DiceActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DiceMesh_MetaData[] = {
		{ "Category", "DiceActor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Static Mesh Component for the Dice\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DiceActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Static Mesh Component for the Dice" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Arrow1_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Timer handle for checking when dice stops\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DiceActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Timer handle for checking when dice stops" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Arrow2_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Dice" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DiceActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Arrow3_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Dice" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DiceActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Arrow4_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Dice" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DiceActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Arrow5_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Dice" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DiceActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Arrow6_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Dice" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DiceActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DiceMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Arrow1;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Arrow2;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Arrow3;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Arrow4;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Arrow5;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Arrow6;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADiceActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADiceActor_Statics::NewProp_DiceMesh = { "DiceMesh", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceActor, DiceMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DiceMesh_MetaData), NewProp_DiceMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADiceActor_Statics::NewProp_Arrow1 = { "Arrow1", nullptr, (EPropertyFlags)0x00400000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceActor, Arrow1), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Arrow1_MetaData), NewProp_Arrow1_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADiceActor_Statics::NewProp_Arrow2 = { "Arrow2", nullptr, (EPropertyFlags)0x00400000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceActor, Arrow2), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Arrow2_MetaData), NewProp_Arrow2_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADiceActor_Statics::NewProp_Arrow3 = { "Arrow3", nullptr, (EPropertyFlags)0x00400000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceActor, Arrow3), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Arrow3_MetaData), NewProp_Arrow3_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADiceActor_Statics::NewProp_Arrow4 = { "Arrow4", nullptr, (EPropertyFlags)0x00400000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceActor, Arrow4), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Arrow4_MetaData), NewProp_Arrow4_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADiceActor_Statics::NewProp_Arrow5 = { "Arrow5", nullptr, (EPropertyFlags)0x00400000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceActor, Arrow5), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Arrow5_MetaData), NewProp_Arrow5_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADiceActor_Statics::NewProp_Arrow6 = { "Arrow6", nullptr, (EPropertyFlags)0x00400000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceActor, Arrow6), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Arrow6_MetaData), NewProp_Arrow6_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADiceActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceActor_Statics::NewProp_DiceMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceActor_Statics::NewProp_Arrow1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceActor_Statics::NewProp_Arrow2,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceActor_Statics::NewProp_Arrow3,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceActor_Statics::NewProp_Arrow4,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceActor_Statics::NewProp_Arrow5,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceActor_Statics::NewProp_Arrow6,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADiceActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ADiceActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_partyGames_2025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADiceActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADiceActor_Statics::ClassParams = {
	&ADiceActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ADiceActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ADiceActor_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADiceActor_Statics::Class_MetaDataParams), Z_Construct_UClass_ADiceActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADiceActor()
{
	if (!Z_Registration_Info_UClass_ADiceActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADiceActor.OuterSingleton, Z_Construct_UClass_ADiceActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADiceActor.OuterSingleton;
}
template<> PARTYGAMES_2025_API UClass* StaticClass<ADiceActor>()
{
	return ADiceActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADiceActor);
ADiceActor::~ADiceActor() {}
// End Class ADiceActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_partyGames_2025_Source_partyGames_2025_Public_DiceActor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADiceActor, ADiceActor::StaticClass, TEXT("ADiceActor"), &Z_Registration_Info_UClass_ADiceActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADiceActor), 1353617761U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_partyGames_2025_Source_partyGames_2025_Public_DiceActor_h_1819541259(TEXT("/Script/partyGames_2025"),
	Z_CompiledInDeferFile_FID_partyGames_2025_Source_partyGames_2025_Public_DiceActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_partyGames_2025_Source_partyGames_2025_Public_DiceActor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
