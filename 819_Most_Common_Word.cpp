#include <iostream>
#include <algorithm>

class Solution {
public:
	std::string mostCommonWord(std::string s, std::vector<std::string>& banned) {
		std::unordered_map<std::string, unsigned> table {};

		for (std::size_t pos = 0; pos < s.size(); ) {
			std::string word = {};
			for (; std::isalpha(s[pos]) && pos < s.size(); ++pos)
				word += static_cast<char>(std::tolower(s[pos]));
			++table[word];

			for (; !std::isalpha(s[pos]) && pos < s.size(); ++pos)
				;
		}

		std::vector<std::pair<std::string, unsigned>> vectorized {};
		vectorized.reserve(table.size());
		std::copy(table.begin(), table.end(), std::back_inserter(vectorized));

		std::sort(vectorized.begin(), vectorized.end(),
			[](const auto& a, const auto& b) {
				return a.second > b.second;
		});

		for (auto & i : vectorized)
			if (std::find(banned.begin(), banned.end(), i.first) == banned.end())
				return i.first;

		return {};
	}
};

int main() {
	{
		const std::string words = "Bob hit a ball, the hit BALL flew far after it was hit.";
		std::vector<std::string> banned = { "hit" };
		std::cout << Solution().mostCommonWord(words, banned) << std::endl << "ball" << std::endl << std::endl;
	}
	{
		const std::string words = "a.";
		std::vector<std::string> banned = { };
		std::cout << Solution().mostCommonWord(words, banned) << std::endl << "a" << std::endl << std::endl;
	}
}