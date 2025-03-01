#include <iostream>

class Solution {
public:
	int missingNumber(std::vector<int>& nums) {
		unsigned count = 0;
		for(int& value: nums)
			count += value;
		return static_cast<int>(nums.size() * (nums.size() + 1) / 2 - count);
	}
};