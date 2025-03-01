#include <iostream>

class Solution {
public:
	std::vector<int> productExceptSelf(const std::vector<int>& nums) {
		std::vector<int> result (nums.size(), 0),
			suffix (nums.size(), 1),
			prefix (nums.size(), 1);

		prefix[0] = nums[0];
		suffix.back() = nums.back();
		for (std::size_t i = 1; i < nums.size(); ++i)
			prefix[i] = prefix[i - 1] * nums[i];

		for (auto i = static_cast<long long>(nums.size() - 2); i >= 0; --i) {
			suffix[i] = suffix[i + 1] * nums[i];
		}

		result[0] = suffix[1];
		result.back() = prefix[prefix.size() - 2];

		for (std::size_t i = 1; i < nums.size() - 1; ++i)
			result[i] = prefix[i - 1] * suffix[i + 1];

		return result;
	}
};

int main() {
	{
		const std::vector nums = {2, 3, 4, 5};
		for (const auto i : Solution().productExceptSelf(nums))
			std::cout << i << ' ';
		std::cout << std::endl;
		for (const auto i : {60, 40, 30, 24})
			std::cout << i << " ";
		std::cout << std::endl << std::endl;
	}

	{
		const std::vector<int> nums = {1, 2, 3, 4};
		for (const auto i : Solution().productExceptSelf(nums))
			std::cout << i << " ";
		std::cout << std::endl;
		for (const auto i : {24,12,8,6})
			std::cout << i << " ";
		std::cout << std::endl << std::endl;
	}

	{
		const std::vector nums = {-1,1,0,-3,3};
		for (const auto i : Solution().productExceptSelf(nums))
			std::cout << i << ' ';
		std::cout << std::endl;
		for (const auto i : {0,0,9,0,0})
			std::cout << i << " ";
		std::cout << std::endl << std::endl;
	}
}