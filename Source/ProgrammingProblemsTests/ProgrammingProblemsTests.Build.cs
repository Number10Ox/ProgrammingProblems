using UnrealBuildTool;

public class ProgrammingProblemsTests : ModuleRules
{
    public ProgrammingProblemsTests(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "AutomationController" });

        PrivateDependencyModuleNames.AddRange(new string[] { "ProgrammingProblems" });
        
        RuntimeDependencies.Add("$(ProjectDir)/Source/ProgrammingProblems/TextJustify.cpp");
        RuntimeDependencies.Add("$(ProjectDir)/Source/ProgrammingProblems/LCS.cpp");
        RuntimeDependencies.Add("$(ProjectDir)/Source/ProgrammingProblems/AlignedAlloc.cpp");
        RuntimeDependencies.Add("$(ProjectDir)/Source/ProgrammingProblems/Blit.cpp");
    }
}

