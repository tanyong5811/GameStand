// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MCAIR.h"


#define LOCTEXT_NAMESPACE "FMCAIRModule"

void FMCAIRModule::StartupModule()
{
}

void FMCAIRModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMCAIRModule, MCAIR)