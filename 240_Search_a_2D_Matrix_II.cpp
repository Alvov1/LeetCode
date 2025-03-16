#include <iostream>

// Two solutions, both looks like not the fastest ones.
// Mine's just quitting the loop when encountered element greater.

class Solution {
public:

	bool searchMatrixMine(const std::vector<std::vector<int>>& matrix, int target) {
		for (std::size_t i = 0; i < matrix.size(); i++) {
			for (std::size_t j = 0; j < matrix[0].size(); j++) {
				if (matrix[i][j] == target)
					return true;
				if (matrix[i][j] > target)
					break;
			}
			if (matrix[i][0] > target)
				break;
		}
		return false;
	}

	bool searchMatrixAlgoMonster(const std::vector<std::vector<int>>& matrix, int target) {
		const std::size_t M = matrix.size(), N = matrix[0].size();
		long long i = static_cast<long long>(M - 1), j = 0;

		while (i >= 0 && j < N) {
			if (matrix[i][j] == target)
				return true;
			if (matrix[i][j] > target) {
				--i;
			} else {
				++j;
			}
		}

		return false;
	}
};

int main() {
	std::cout << std::boolalpha;
	{
		std::vector<std::vector<int>> matrix = {
		{1, 4, 7, 11, 15},
		{2, 5, 8, 12, 19},
		{3, 6, 9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30}
		};
		std::cout << Solution().searchMatrixMine(matrix, 5) << std::endl;
		std::cout << Solution().searchMatrixAlgoMonster(matrix, 5) << std::endl;
		std::cout << true << std::endl << std::endl;
	}
	{
		std::vector<std::vector<int>> matrix = {
			{1, 4, 7, 11, 15},
			{2, 5, 8, 12, 19},
			{3, 6, 9, 16, 22},
			{10, 13, 14, 17, 24},
			{18, 21, 23, 26, 30}
		};
		std::cout << Solution().searchMatrixMine(matrix, 20) << std::endl;
		std::cout << Solution().searchMatrixAlgoMonster(matrix, 20) << std::endl;
		std::cout << false << std::endl << std::endl;
	}
	{
		std::vector<std::vector<int>> matrix = {
			{-5},
		};
		std::cout << Solution().searchMatrixMine(matrix, -5) << std::endl;
		std::cout << Solution().searchMatrixAlgoMonster(matrix, -5) << std::endl;
		std::cout << true << std::endl << std::endl;
	}
	{
		std::vector<std::vector<int>> matrix = {
			{1, 1},
		};
		std::cout << Solution().searchMatrixMine(matrix, 1) << std::endl;
		std::cout << Solution().searchMatrixAlgoMonster(matrix, 1) << std::endl;
		std::cout << true << std::endl << std::endl;
	}
}
