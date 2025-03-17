#include <iostream>
#include <unordered_set>

class Solution {
public:
	int lengthOfLongestSubstring(const std::string& s) {
		std::unordered_set<char> currentCharacters {};

		std::size_t start = 0, maxLength = 0;
		for (std::size_t end = 0; end < s.size(); ++end) {
			for (; currentCharacters.contains(s[end]); start += 1)
				currentCharacters.erase(s[start]);

			currentCharacters.insert(s[end]);
			maxLength = std::max(maxLength, end - start + 1);
		}

		return static_cast<int>(maxLength);
	}
};

int main() {
	std::cout << Solution().lengthOfLongestSubstring("abcabcbb") << std::endl << 3 << std::endl << std::endl;
	std::cout << Solution().lengthOfLongestSubstring("bbbbb") << std::endl << 1 << std::endl << std::endl;
	std::cout << Solution().lengthOfLongestSubstring("pwwkew") << std::endl << 3 << std::endl << std::endl;
	std::cout << Solution().lengthOfLongestSubstring(" ") << std::endl << 1 << std::endl << std::endl;
	std::cout << Solution().lengthOfLongestSubstring("dvdf") << std::endl << 3 << std::endl << std::endl;
}
