// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BoardPawn.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef PARTYGAMES_2025_BoardPawn_generated_h
#error "BoardPawn.generated.h already included, missing '#pragma once' in BoardPawn.h"
#endif
#define PARTYGAMES_2025_BoardPawn_generated_h

#define FID_partyGames_2025_Source_partyGames_2025_Public_BoardPawn_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnPawnOverlap);


#define FID_partyGames_2025_Source_partyGames_2025_Public_BoardPawn_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABoardPawn(); \
	friend struct Z_Construct_UClass_ABoardPawn_Statics; \
public: \
	DECLARE_CLASS(ABoardPawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/partyGames_2025"), NO_API) \
	DECLARE_SERIALIZER(ABoardPawn)


#define FID_partyGames_2025_Source_partyGames_2025_Public_BoardPawn_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ABoardPawn(ABoardPawn&&); \
	ABoardPawn(const ABoardPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoardPawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoardPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABoardPawn) \
	NO_API virtual ~ABoardPawn();


#define FID_partyGames_2025_Source_partyGames_2025_Public_BoardPawn_h_10_PROLOG
#define FID_partyGames_2025_Source_partyGames_2025_Public_BoardPawn_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_partyGames_2025_Source_partyGames_2025_Public_BoardPawn_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_partyGames_2025_Source_partyGames_2025_Public_BoardPawn_h_13_INCLASS_NO_PURE_DECLS \
	FID_partyGames_2025_Source_partyGames_2025_Public_BoardPawn_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PARTYGAMES_2025_API UClass* StaticClass<class ABoardPawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_partyGames_2025_Source_partyGames_2025_Public_BoardPawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
