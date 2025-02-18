// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PartyGameGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PARTYGAMES_2025_PartyGameGameMode_generated_h
#error "PartyGameGameMode.generated.h already included, missing '#pragma once' in PartyGameGameMode.h"
#endif
#define PARTYGAMES_2025_PartyGameGameMode_generated_h

#define FID_partyGames_2025_Source_partyGames_2025_Public_PartyGameGameMode_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPartyGameGameMode(); \
	friend struct Z_Construct_UClass_APartyGameGameMode_Statics; \
public: \
	DECLARE_CLASS(APartyGameGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/partyGames_2025"), NO_API) \
	DECLARE_SERIALIZER(APartyGameGameMode)


#define FID_partyGames_2025_Source_partyGames_2025_Public_PartyGameGameMode_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APartyGameGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	APartyGameGameMode(APartyGameGameMode&&); \
	APartyGameGameMode(const APartyGameGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APartyGameGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APartyGameGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APartyGameGameMode) \
	NO_API virtual ~APartyGameGameMode();


#define FID_partyGames_2025_Source_partyGames_2025_Public_PartyGameGameMode_h_13_PROLOG
#define FID_partyGames_2025_Source_partyGames_2025_Public_PartyGameGameMode_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_partyGames_2025_Source_partyGames_2025_Public_PartyGameGameMode_h_16_INCLASS_NO_PURE_DECLS \
	FID_partyGames_2025_Source_partyGames_2025_Public_PartyGameGameMode_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PARTYGAMES_2025_API UClass* StaticClass<class APartyGameGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_partyGames_2025_Source_partyGames_2025_Public_PartyGameGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
