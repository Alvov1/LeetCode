#include <iostream>

class Solution {
public:
	std::vector<int> prisonAfterNDays(const std::vector<int>& cells, int n) {
		std::vector<int> copy1 = cells, copy2 = cells;

		std::vector<int> firstMove (cells.size());
		change(cells, firstMove);

		for (std::size_t i = 0; i < 10000; ++i) {
			if (i % 2 == 0) {
				change(copy1, copy2);
				// std::cout << "# " << i << ": [ ";
				// for (auto v: copy2)
				// 	std::cout << v << ' ';
				// std::cout << "]" << std::endl;
				if (copy2 == firstMove && i > 0) {
					std::cout << "FOUND!!!: " << i << std::endl;
					break;
				}
			} else {
				change(copy2, copy1);
				// std::cout << "# " << i << ": [ ";
				// for (auto v: copy1)
				// 	std::cout << v << ' ';
				// std::cout << "]" << std::endl;
				if (copy1 == firstMove && i > 0) {
					std::cout << "FOUND!!!: " << i << std::endl;
					break;
				}
			}
		}
		return copy1;
	}

	void change(const std::vector<int>& from, std::vector<int>& to) {
		if (from.size() != to.size())
			throw std::invalid_argument("Invalid input");

		for (std::size_t i = 1; i < from.size() - 1; ++i)
			if (from[i - 1] == from[i + 1])
				to[i] = 1; else to[i] = 0;
		to[0] = 0; to.back() = 0;
	}
};

int main() {
	{
		const std::vector<int> cells = {0,1,0,1,1,0,0,1},
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
		for (auto v: result)
			std::cout << v << ' ';
		std::cout << std::endl;
		for (auto v: required)
			std::cout << v << ' ';
		std::cout << std::endl << std::endl;
	}
}