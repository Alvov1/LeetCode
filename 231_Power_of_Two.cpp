#include <iostream>
#include <bit>

class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0) return false;
		const auto base = static_cast<unsigned long>(n);
		const auto bitLength = (8 * sizeof base) - std::countl_zero(base);
		const auto stamp = ~(1ul << bitLength - 1);
		return (base & stamp) == 0ul;
	}
};

int main() {
	std::cout << std::boolalpha;
	std::cout << Solution().isPowerOfTwo(1048576) << std::endl;
	std::cout << Solution().isPowerOfTwo(2) << std::endl;
	std::cout << Solution().isPowerOfTwo(3) << std::endl;
	std::cout << Solution().isPowerOfTwo(32) << std::endl;
	std::cout << Solution().isPowerOfTwo(34) << std::endl;
	std::cout << Solution().isPowerOfTwo(128) << std::endl;
	std::cout << Solution().isPowerOfTwo(124) << std::endl;
	std::cout << Solution().isPowerOfTwo(512) << std::endl;
	std::cout << Solution().isPowerOfTwo(546) << std::endl;
	std::cout << Solution().isPowerOfTwo(1024) << std::endl;
	std::cout << Solution().isPowerOfTwo(1060) << std::endl;
	std::cout << Solution().isPowerOfTwo(4096) << std::endl;
	std::cout << Solution().isPowerOfTwo(4100) << std::endl;
	std::cout << Solution().isPowerOfTwo(8192) << std::endl;
	std::cout << Solution().isPowerOfTwo(8240) << std::endl;
}