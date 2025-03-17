#include <iostream>
#include <unordered_set>

class Solution {
public:
	bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
		std::vector<bool> canSegment (s.size() + 1);
		canSegment[0] = true;

		for (std::size_t i = 1; i < s.size() + 1; ++i)
			for (std::size_t j = 0; j < i; ++j) {
				if (!canSegment[j]) continue;

				const auto it = std::find(wordDict.begin(), wordDict.end(), s.substr(j, i - j));
				if (it != wordDict.end()) {
					canSegment[i] = true;
					break;
				}
			}

		return canSegment[s.size()];
	}
};

int main() {
	std::cout << std::boolalpha;
	{
		std::string data = "leetcode";
		std::vector<std::string> wordDict = {"leet","code"};
		std::cout << Solution().wordBreak(data, wordDict) << std::endl << true << std::endl << std::endl;
	}

	{
		std::string data = "applepenapple";
		std::vector<std::string> wordDict = {"apple","pen"};
		std::cout << Solution().wordBreak(data, wordDict) << std::endl << true << std::endl << std::endl;
	}

	{
		std::string data = "catsandog";
		std::vector<std::string> wordDict = {"cats","dog","sand","and","cat"};
		std::cout << Solution().wordBreak(data, wordDict) << std::endl << false << std::endl << std::endl;
	}
}