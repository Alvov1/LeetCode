#include <iostream>

class Solution {
public:
	int maxSubArray(const std::vector<int>& nums) {
		int max = std::numeric_limits<int>::min();
		int temp = std::numeric_limits<int>::min();
		bool startOver = true;

		for (auto i : nums) {
			if (startOver) {
				max = std::max(max, i);
				if (i < 0) // Skip negative elements when we're starting over
					continue;
				startOver = false;
				temp = i;
			} else {
				// Adding to the solution
				if (i >= 0) {
					temp += i;
					max = std::max(temp, max);
				} else {
					const auto temp2 = temp + i;
					if (temp2 >= 0) {
						temp = temp2;
						max = std::max(temp, max);
					} else startOver = true;
				}
			}
		}

		return max;
	}
};