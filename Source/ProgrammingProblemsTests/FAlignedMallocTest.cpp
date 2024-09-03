#if WITH_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"

#include "../ProgrammingProblems/AlignedAlloc.h"

BEGIN_DEFINE_SPEC(FAlignedMallocProblemSpec, "ProgrammingProblems.AlignedMallocProblemTests",
                  EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

END_DEFINE_SPEC(FAlignedMallocProblemSpec)

void FAlignedMallocProblemSpec::Define()
{
	Describe("AlignedMalloc", [this]()
	{
		// Malloc test
		It("Allocate and free 1 byte with 8 byte alignment", [this]()
		{
			void *ptr = AlignedAlloc(1, 4);
			*static_cast<char *>(ptr) = 'a';
			AlignedFree(ptr);
		});
	});
}

#endif // WITH_AUTOMATION_TESTS
