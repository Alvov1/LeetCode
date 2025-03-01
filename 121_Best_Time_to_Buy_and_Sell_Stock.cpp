#include <iostream>

class Solution {
public:
	int maxProfit(std::vector<int>& prices) {
		int currentMax = prices[0],
			currentMin = prices[0],
			maxProfit = 0;

		for (const auto price: prices) {
			if (price > currentMax) {
				currentMax = price;
				if (currentMax - currentMin > maxProfit)
					maxProfit = currentMax - currentMin;
			}

			if (price < currentMin) {
				currentMin = price;
				currentMax = currentMin;
			}
		}

		return maxProfit;
	}
};

int main() {
	{
		std::vector values = {7,1,5,3,6,4};
		std::cout << Solution().maxProfit(values) << std::endl << 5 << std::endl << std::endl;
	}
	{
		std::vector values = {7,6,4,3,1};
		std::cout << Solution().maxProfit(values) << std::endl << 0 << std::endl << std::endl;
	}
	{
		std::vector values = {3,2,6,5,0,3};
		std::cout << Solution().maxProfit(values) << std::endl << 4 << std::endl << std::endl;
	}
}