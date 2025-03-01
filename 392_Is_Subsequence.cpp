#include <iostream>

class Solution {
public:
	bool isSubsequence(const std::string& pattern, const std::string& string) {
		unsigned pattP = 0;
		for(unsigned i = 0; i < string.size() && pattP < pattern.size(); ++i)
			if(string[i] == pattern[pattP]) pattP++;
		return pattP == pattern.size();
	}
};