#pragma once

#include <vector>
#include <string>

std::vector<std::string> FullJustify(std::vector<std::string>& words, int maxWidth);
int NumberOfWordsToSelectForLineOfWidth(const std::vector<std::string>& words, int maxWidth);
std::string JustifiedTextLineFromWords(const std::vector<std::string>& words, const int maxWidth);
std::string FillLineWithWords(const std::vector<std::string>& words, const int maxWidth);