#include <iostream>

class Solution {
public:
	bool isPalindrome(std::string s) {
		s.erase(std::remove_if(s.begin(), s.end(), [](char c) { return !std::isalnum(c); } ), s.end());
		for(unsigned i = 0; i < s.size() / 2; ++i)
			if(std::tolower(s[i]) != std::tolower(s[s.size() - i - 1])) return false;
		return true;
	}
};