

// LCS Problem Statement: Given two sequences, find the length of longest subsequence
// present in both of them. A subsequence is a sequence that appears in the same relative
// order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”,
// ‘”acefg”, .. etc are subsequences of “abcdefg”. So a string of length n has 2^n
// different possible subsequences
//
// LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3
// LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

int LongestSubsequenceInSequences(const std::string& sequence1, const std::string& sequence2);
bool SubsequenceIsInSequence(const std::string& subsequence, const std::string& sequence);
std::vector<std::string> GenerateSubsequences(const std::string& sequence);