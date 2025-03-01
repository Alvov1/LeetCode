#include <iostream>

class Solution {
public:
	std::string addStrings(std::string num1, std::string num2) {
		const std::size_t totalLength = std::max(num1.size(), num2.size());

		std::string result {};
		result.reserve(totalLength);

		int add = 0;

		long long position1 = static_cast<long long>(num1.size()) - 1,
			position2 = static_cast<long long>(num2.size()) - 1;
		for (; position1 >= 0 && position2 >= 0; position1--, position2--) {
			const auto l = num1[position1] - '0', r = num2[position2] - '0';
			const auto currentSum = l + r + add;
			result += (currentSum % 10) + '0';
			add = currentSum / 10;
		}

		for (; position1 >= 0; --position1) {
			const auto currentSum = num1[position1] - '0' + add;
			result += (currentSum % 10) + '0';
			add = currentSum / 10;
		}
		for (; position2 >= 0; --position2) {
			const auto currentSum = num2[position2] - '0' + add;
			result += (currentSum % 10) + '0';
			add = currentSum / 10;
		}

		if (add > 0)
			result += static_cast<char>('0' + add);

		return { result.rbegin(), result.rend() };
	}
};

int main() {
	std::cout << Solution().addStrings("11", "123") << std::endl << "134" << std::endl << std::endl;
	std::cout << Solution().addStrings("456", "77") << std::endl << "533" << std::endl << std::endl;
	std::cout << Solution().addStrings("0", "0") << std::endl << "0" << std::endl << std::endl;
	std::cout << Solution().addStrings("9133", "0") << std::endl << "9133" << std::endl << std::endl;
}