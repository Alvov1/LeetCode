#include <iostream>

class Solution {
	std::vector<int> processPeriod(std::vector<int>& lastChange,
		std::vector<int>& buffer, const std::size_t period, int n) {
		const auto remainShift = n % period;

		for (std::size_t i = 0; i < remainShift; ++i) {
			if (i % 2 == 0) {
				change(lastChange, buffer);
			} else {
				change(buffer, lastChange);
			}
		}

		if (remainShift % 2 == 0)
			return lastChange;
		return buffer;
	}

public:
	std::vector<int> prisonAfterNDays(const std::vector<int>& cells, int n) {
		std::vector<int> firstMove (cells.size());
		change(cells, firstMove);
		--n;

		std::vector<int> left = firstMove, right (cells.size());

		for (std::size_t i = 0; i < n; ++i) {
			if (i % 2 == 0) {
				change(left, right);
				if (i > 0 && right == firstMove)
					return processPeriod(right, left, i + 1, n);
			} else {
				change(right, left);
				if (i > 0 && left == firstMove)
					return processPeriod(left, right, i + 1, n);
			}
		}

		if (n % 2 == 0)
			return left; else return right;
	}

	void change(const std::vector<int>& from, std::vector<int>& to) {
		for (std::size_t i = 1; i < from.size() - 1; ++i)
			if (from[i - 1] == from[i + 1])
				to[i] = 1; else to[i] = 0;
		to[0] = 0; to.back() = 0;
	}
};

int main() {
	{
		std::vector<int> cells = {0,1,0,1,1,0,0,1},
			required = {0,0,1,1,0,0,0,0};
		const auto result = Solution().prisonAfterNDays(cells, 7);
		for (auto v: result)
			std::cout << v << ' ';
		std::cout << std::endl;
		for (auto v: required)
			std::cout << v << ' ';
		std::cout << std::endl << std::endl;
	}
	{
		const std::vector<int> cells = {1,0,0,1,0,0,1,0},
					required = {0,0,1,1,1,1,1,0};
		const auto result = Solution().prisonAfterNDays(cells, 1000000000);

		std::cout << std::endl << std::endl << std::endl;
		for (auto v: result)
			std::cout << v << ' ';
		std::cout << std::endl;
		for (auto v: required)
			std::cout << v << ' ';
		std::cout << std::endl << std::endl;
	}
}