#include "LCS.h"
#include <string>
#include <vector>

__attribute__((visibility("default")))
std::vector<std::string> GenerateSubsequences(const std::string& sequence)
{
	std::vector<std::string> subsequences;

	if (sequence.length() == 0)
	{
		return subsequences;
	}
	if (sequence.length() == 1)
	{
		subsequences.push_back(sequence.substr(0, 1));
		return subsequences;
	}

	// add car(sequence)
	subsequences.push_back(sequence.substr(0, 1));

	// add subsequences of car() with each of the cdr() subsequences
	std::vector<std::string> cdrSubsequences = GenerateSubsequences(sequence.substr(1, sequence.length() - 1));
	for (int j = 0; j < cdrSubsequences.size(); ++j)
	{
		std::string subsequence;
		subsequence.append(sequence.substr(0, 1));
		subsequence.append(cdrSubsequences[j]);
		subsequences.push_back(subsequence);
	}

	// Add all of the "cdr" subsequences
	subsequences.insert(subsequences.end(), cdrSubsequences.begin(), cdrSubsequences.end());
	
	return subsequences;
}

__attribute__((visibility("default")))
int LongestSubsequenceInSequences(const std::string& sequence1, const std::string& sequence2)
{
	int longestSharedSubsequence = 0;
	const std::vector<std::string> subsequences = GenerateSubsequences(sequence1);
	for (std::string subsequence : subsequences)
	{
		const bool result = SubsequenceIsInSequence(subsequence, sequence2);
		if (result && subsequence.length() > longestSharedSubsequence)
		{
			longestSharedSubsequence = subsequence.length();
		}
	}

	return longestSharedSubsequence;
}

__attribute__((visibility("default")))
bool SubsequenceIsInSequence(const std::string& subsequence, const std::string& sequence)
{
	if (subsequence.empty())
	{
		return false;
	}

	int currentSequencePosition = 0;
	for (int i = 0; i < subsequence.length(); ++i)
	{
		if (currentSequencePosition >= sequence.length())
		{
			return false;
		}
			
		bool nextCharacterFound = false;
		for (int j = currentSequencePosition; j < sequence.length(); ++j)
		{
			if (sequence[j] == subsequence[i])
			{
				currentSequencePosition = j + 1;
				nextCharacterFound = true;
				break;
			}
		}
		if (!nextCharacterFound)
		{
			return false;
		}
	}

	return true;
}
