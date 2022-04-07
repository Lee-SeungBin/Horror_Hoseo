// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Final_1 : ModuleRules
{
	public Final_1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
