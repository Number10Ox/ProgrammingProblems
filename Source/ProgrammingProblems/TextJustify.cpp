
#include "TextJustify.h"

#include <numeric>

__attribute__((visibility("default"))) 
std::vector<std::string> FullJustify(std::vector<std::string>& words, int maxWidth)
{
	std::vector<std::string> justifiedText;
	
	auto itr = words.begin();	
	while (itr != words.end())
	{
		std::vector<std::string> remainingWords(itr, words.end());
		int numberOfWordsToSelectForLine = NumberOfWordsToSelectForLineOfWidth(remainingWords, maxWidth);
		std::vector<std::string> selectedwords(itr, itr + numberOfWordsToSelectForLine);

		std::string nextLine;
		std::advance(itr, numberOfWordsToSelectForLine);

		// Need to handle all lines but the last line the same
		if (itr != words.end())
		{
			nextLine = JustifiedTextLineFromWords(selectedwords, maxWidth);
		}
		else
		{
			nextLine = FillLineWithWords(selectedwords, maxWidth);
		}
		justifiedText.push_back(nextLine);
	}
	
	return justifiedText;
}

__attribute__((visibility("default"))) 
int NumberOfWordsToSelectForLineOfWidth(const std::vector<std::string>& words, const int maxWidth)
{
	int numSelectedWords = 0;
	int numCharactersUsed = 0;

	for (std::string word :words)
	{
		if (const int wordLength = word.length(); wordLength + numCharactersUsed <= maxWidth)
		{
			numCharactersUsed += wordLength + 1; // add one for space after word
			numSelectedWords++;
		}
		else
		{
			break;	
		}
	}

	return numSelectedWords;
}

__attribute__((visibility("default")))
std::string JustifiedTextLineFromWords(const std::vector<std::string>& words, const int maxWidth)
{
	std::string result;
	result.reserve(maxWidth);

	int totalCharacterLength = std::accumulate(words.begin(), words.end(), 0, 
	[](int sum, const std::string& word) {
		return sum + word.length();
	});

	if (words.size() == 1)
	{
		result.append(words[0]);
		result.append(maxWidth - totalCharacterLength,' ');
	}
	else
	{
		int whiteSpaceCount = maxWidth - totalCharacterLength;
		int numWordGaps = words.size() - 1;
		int spacesPerGap = numWordGaps > 0 ? whiteSpaceCount / numWordGaps : 0;
		int extraSpacesToFillLeftToRight = whiteSpaceCount -  spacesPerGap * numWordGaps;

		for (auto i = 0; i < words.size(); ++i)
		{
			result.append(words[i]);
			if (i < words.size() - 1)
			{
				result.append(spacesPerGap, ' ');
				if (extraSpacesToFillLeftToRight > 0)
				{
					result.append(" ");
					extraSpacesToFillLeftToRight--;
				}
			} 
		}
	}

	return result;
}

__attribute__((visibility("default")))
std::string FillLineWithWords(const std::vector<std::string>& words, const int maxWidth)
{
	std::string result;
	result.reserve(maxWidth);

	for (size_t i = 0; i < words.size(); ++i)
	{
		if (i > 0)
		{
			result.append(" ");
		}
		result.append(words[i]);
	}

	result.append(maxWidth - result.length(), ' ');
	return result;
}