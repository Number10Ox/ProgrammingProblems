#include <vector>
#if WITH_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"
#include <string>

#include "ProgrammingProblems/LCS.h"

BEGIN_DEFINE_SPEC(FLCSProblemSpec, "ProgrammingProblems.LCSProblemTests",
                  EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

END_DEFINE_SPEC(FLCSProblemSpec)

void FLCSProblemSpec::Define()
{
	Describe("LCS", [this]()
	{
		// Subsequence tests
		It("Should return true that ADH is a sequence in AEDFHR", [this]()
		{
			const std::string subsequence("ADH");
			const std::string sequence("AEDFHR");
			TestTrue("ADH is a sequence in AEDFHR", SubsequenceIsInSequence(subsequence, sequence));
		});

		It("Should return false that FROG is a sequence in AEDFHR", [this]()
		{
			const std::string subsequence("FROG");
			const std::string sequence("AEDFHR");
			TestFalse("FROG is a sequence in AEDFHR", SubsequenceIsInSequence(subsequence, sequence));
		});

		// Generate All Sequences Tests
		It("All Subsequences Test", [this]()
		{
			const std::string sequence("ABCD");

			std::vector<std::string> expectedSubsequences = {
				"A", "B", "C", "D",
				"AB", "AC", "AD", "BC", "BD", "CD",
				"ABC", "ABD", "ACD", "BCD",
				"ABCD"
			};

			std::vector<std::string> subsequences = GenerateSubsequences(sequence);
			TestTrue("Should generate proper subsequences", subsequences == expectedSubsequences);
		});

		// Longest subsequence tests
		It("Two empty strings should return 0", [this]()
		{
			const int longestSubsequence = LongestSubsequenceInSequences("", "");
			TestEqual("Two empty sequences should return 0", longestSubsequence, 0);
		});

		It(" LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3", [this]()
		{
			const int longestSubsequence = LongestSubsequenceInSequences("ABCDGH", "AEDFHR");
			TestEqual("Longest shared sequence should be 3", longestSubsequence, 3);
		});

		It(" LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4", [this]()
		{
			const int longestSubsequence = LongestSubsequenceInSequences("AGGTAB", "GXTXAYB");
			TestEqual("Longest shared sequence should be 4", longestSubsequence, 4);
		});
	});
}

#endif // WITH_AUTOMATION_TESTS
