#include <iostream>

class Solution {
public:
	std::string longestPalindrome(std::string s) {
		std::vector table(s.size(), std::vector(s.size(), false));

		std::size_t startIdx = 0, maxLen = 1;

		for (std::size_t i = 0; i + 1 < s.size(); ++i) {
			table[i][i] = true;
			if (s[i] == s[i + 1]) {
				table[i][i + 1] = true;
				startIdx = i;
				maxLen = 2;
			}
		}

		for (std::size_t len = 3; len <= s.size(); ++len) {
			for (std::size_t i = 0; i < s.size() - len + 1; ++i) {
				const std::size_t j = i + len - 1;
				if (s[i] == s[j] && table[i + 1][j - 1]) {
					table[i][j] = true;

					if (len > maxLen) {
						startIdx = i;
						maxLen = len;
					}
				}
			}
		}

		return s.substr(startIdx, maxLen);
	}
};

int main() {
	std::cout << Solution().longestPalindrome("babad") << std::endl << "bab" << std::endl << std::endl;

	std::cout << Solution().longestPalindrome("cbbd") << std::endl << "bb" << std::endl << std::endl;
}
