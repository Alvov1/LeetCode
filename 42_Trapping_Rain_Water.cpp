#include <iostream>

class Solution {
public:
	int trap(const std::vector<int>& height) {
		if (height.size() < 3) return 0;

		const std::size_t length = height.size();

		/* Checking all left axes. */
		std::vector<int> lAces (length, height[0]);
		for (int i = 1; i < length; ++i)
			lAces[i] = std::max(lAces[i - 1], height[i]);

		/* Checking all right axes. */
		std::vector<int> rAces (length, height[length - 1]);
		for (long long i = static_cast<int>(length) - 2; i >= 0; --i)
			rAces[i] = std::max(rAces[i + 1], height[i]);

		/* Total height = std::min(l, r) - heightHere. */
		int total = 0;
		for (int i = 0; i < length; ++i)
			total += std::min(lAces[i], rAces[i]) - height[i];
		return total;
	}
};

int main() {
	{
		const std::vector values = {0,1,0,2,1,0,1,3,2,1,2,1};
		std::cout << Solution().trap(values) << std::endl <<  6 << std::endl << std::endl;
	}

	{
		const std::vector values = {4,2,0,3,2,5};
		std::cout << Solution().trap(values) << std::endl <<  9 << std::endl << std::endl;
	}
}