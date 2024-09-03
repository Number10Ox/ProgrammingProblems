#if WITH_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"

#include "../ProgrammingProblems/Blit.h"

BEGIN_DEFINE_SPEC(FBlitProblemSpec, "ProgrammingProblems.BlitProblemTests",
				  EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

END_DEFINE_SPEC(FBlitProblemSpec)

void FBlitProblemSpec::Define()
{
	Describe("Blit", [this]()
	{

	});
}

#endif // WITH_AUTOMATION_TESTS
