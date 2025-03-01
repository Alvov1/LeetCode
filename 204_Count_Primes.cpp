#include <iostream>

class Solution {
public:
	int countPrimes(int n) {
		if (n == 0) return 0;
		if (n == 1) return 0;
		if (n == 2) return 0;

		std::vector<bool> primes(n, true);

		/* Starting from position 1 which represents 2 */
		for (std::size_t pos = 2; pos < primes.size();) {
			for (std::size_t j = 2; j * pos < primes.size(); ++j)
				primes[j * pos] = false;
			++pos;
			for (; pos < primes.size() && primes[pos] == false; ++pos)
				;
		}

		int count = -2;
		for (auto && prime : primes)
			if (prime == true) ++count;

		return count;
	}
};

int main() {
	std::cout << Solution().countPrimes(10) << std::endl << 4 << std::endl << std::endl;
	std::cout << Solution().countPrimes(0) << std::endl << 0 << std::endl << std::endl;
	std::cout << Solution().countPrimes(1) << std::endl << 0 << std::endl << std::endl;
	std::cout << Solution().countPrimes(2) << std::endl << 0 << std::endl << std::endl;
	std::cout << Solution().countPrimes(3) << std::endl << 1 << std::endl << std::endl;
}