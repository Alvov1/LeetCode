#include <iostream>

class Solution {
public:
	void moveZeroes(std::vector<int>& nums) {
		for(unsigned sequenceStart = 0; sequenceStart < nums.size(); ++sequenceStart) {
			if(nums[sequenceStart] != 0) continue;

			unsigned sequenceEnd = sequenceStart;
			for(; nums[sequenceEnd] == 0; ++sequenceEnd)
				if(sequenceEnd >= nums.size() - 1) return;

			unsigned long zerosCount = sequenceEnd - sequenceStart;
			unsigned permutationsCount = std::min(zerosCount, nums.size() - sequenceEnd);

			unsigned start = sequenceStart;
			for(unsigned i = 0; i < permutationsCount; ++i, ++start)
				std::swap(nums[start], nums[sequenceEnd++]);
		}
	}
};