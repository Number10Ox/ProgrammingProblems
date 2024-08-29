#if WITH_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"
#include <vector>
#include <string>

#include "ProgrammingProblems/TextJustify.h"

BEGIN_DEFINE_SPEC(FJustificationProblemSpec, "ProgrammingProblems.JustificationProblemTests",
                  EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

END_DEFINE_SPEC(FJustificationProblemSpec)

bool AreVectorsEqual(const std::vector<std::string>& vec1, const std::vector<std::string>& vec2)
{
	if (vec1.size() != vec2.size())
	{
		return false;
	}

	for (size_t i = 0; i < vec1.size(); ++i)
	{
		if (vec1[i] != vec2[i])
		{
			return false;
		}
	}

	return true;
}

void FJustificationProblemSpec::Define()
{
	Describe("Full Justify", [this]()
	{
		// Word Selection Tests
		It("Should return 0 when given an empty vector of words", [this]()
		{
			std::vector<std::string> words;
			const int maxWidth = 10;
			const std::vector<std::string> Result = FullJustify(words, maxWidth);
			const int numberOfWords = NumberOfWordsToSelectForLineOfWidth(words, maxWidth);

			TestEqual("Empty vector should return 0", numberOfWords, 0);
		});

		It("Should return 3 when only the first 3 words should fit with max width 16", [this]()
		{
			std::vector<std::string> words = {"This", "is", "an", "example"};
			const int maxWidth = 16;
			const int numberOfWords = NumberOfWordsToSelectForLineOfWidth(words, maxWidth);

			TestEqual("['This, 'is', 'an', 'example'] should return 3", numberOfWords, 3);
		});

		// Justified Text Line Tests

		It("Return proper justified spacing max with 16", [this]()
		{
			std::vector<std::string> words = {"example", "of", "text"};
			const int maxWidth = 16;
			std::string justifiedLineOfText = JustifiedTextLineFromWords(words, maxWidth);

			TestEqual("['example, 'of', 'text'] should return 'example  of text'", FString(justifiedLineOfText.c_str()),
			          FString(TEXT("example  of text")));
		});

		It("Return proper justified spacing max with 20", [this]()
		{
			std::vector<std::string> words = {"Science", "is", "what", "we"};
			const int maxWidth = 20;
			std::string justifiedLineOfText = JustifiedTextLineFromWords(words, maxWidth);

			TestEqual("['Science', 'is', 'what', 'we' ] should return 'Science  is  what we'", FString(justifiedLineOfText.c_str()),
			          FString(TEXT("Science  is  what we")));
		});

		It("Return proper justified spacing for last line max with 16", [this]()
		{
			std::vector<std::string> words = {"shall", "be"};
			const int maxWidth = 16;
			std::string justifiedLineOfText = FillLineWithWords(words, maxWidth);

			TestEqual("['shall, 'be'] should return 'shall be        ", FString(justifiedLineOfText.c_str()),
			          FString(TEXT("shall be        ")));
		});

		// Full Justify Tests

		It("Should return an empty result when given an empty vector of words", [this]()
		{
			std::vector<std::string> words;
			const int maxWidth = 10;
			const std::vector<std::string> Result = FullJustify(words, maxWidth);

			TestEqual("Empty vector should return an empty result", Result.size(), 0);
		});

		It("Example 1 should return expected result", [this]()
		{
			std::vector<std::string> words = {"This", "is", "an", "example", "of", "text", "justification."};
			const int maxWidth = 16;
			const std::vector<std::string> result = FullJustify(words, maxWidth);

			std::vector<std::string> expectedResult =
			{
				"This    is    an",
				"example  of text",
				"justification.  "
			};

			TestTrue("Example 1 should return expected result", AreVectorsEqual(result, expectedResult));
		});

		It("Example 2 should return expected result", [this]()
		{
			std::vector<std::string> words = {"What", "must", "be", "acknowledgment", "shall", "be"};
			const int maxWidth = 16;
			const std::vector<std::string> result = FullJustify(words, maxWidth);

			std::vector<std::string> expectedResult =
			{
				"What   must   be",
				"acknowledgment  ",
				"shall be        "
			};

			TestTrue("Example 2 should return expected result", AreVectorsEqual(result, expectedResult));
		});

		It("Example 3 should return expected result", [this]()
		{
			std::vector<std::string> words = {
				"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.",
				"Art", "is", "everything", "else", "we", "do"
			};
			const int maxWidth = 20;
			const std::vector<std::string> result = FullJustify(words, maxWidth);

			std::vector<std::string> expectedResult =
			{
				"Science  is  what we",
				"understand      well",
				"enough to explain to",
				"a  computer.  Art is",
				"everything  else  we",
				"do                  "
			};

			TestTrue("Example 3 should return expected result", AreVectorsEqual(result, expectedResult));
		});
	});
}

#endif // WITH_AUTOMATION_TESTS
