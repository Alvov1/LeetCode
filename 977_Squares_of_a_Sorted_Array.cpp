#include <iostream>

class Solution {
public:
	std::vector<int> sortedSquares(std::vector<int>& nums) {
		std::vector<int> data; data.reserve(nums.size());

		long positive = 0;
		for(; positive < nums.size() && nums[positive] < 0; positive++);

		long negative = positive - 1;
		while(data.size() < nums.size()) {
			if(negative > -1) {
				if(positive < nums.size()){
					if (nums[negative] * nums[negative] < nums[positive] * nums[positive]) {
						data.push_back(nums[negative] * nums[negative]);
						negative--;
					} else {
						data.push_back(nums[positive] * nums[positive]);
						positive++;
					}
				} else {
					data.push_back(nums[negative] * nums[negative]);
					negative--;
				}
			} else {
				data.push_back(nums[positive] * nums[positive]);
				positive++;
			}
		}
		return data;
	}
};