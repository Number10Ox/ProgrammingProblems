// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ProgrammingProblems : ModuleRules
{
    public ProgrammingProblems(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "AutomationController" });

        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}

