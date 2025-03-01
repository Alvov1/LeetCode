#include <iostream>

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& numbers, int target) {
		int left = 0;
		int right = static_cast<int>(numbers.size()) - 1;

		while(true) {
			int sum = numbers[left] + numbers[right];
			if(sum > target)
				--right;
			else if(sum < target)
				++left;
			else return { left + 1, right + 1 };
		}
	}
};