#include <iostream>

class Solution {
public:
	int orangesRotting(std::vector<std::vector<int>>& grid) {
		std::size_t minutes = 0, total = 0, allNodes = 0;
		for (std::size_t i = 0; i < grid.size(); i++)
			for (std::size_t j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 2)
					++total;
				if (grid[i][j] > 0)
					++allNodes;
			}

		int currentChange = 2;

		for (; total < allNodes; ++minutes) {
			std::size_t tempTotal = total;

			for (std::size_t i = 0; i < grid.size(); ++i) {
				for (std::size_t j = 0; j < grid[0].size(); ++j) {
					if (grid[i][j] == currentChange) {
						if (i > 0 && grid[i - 1][j] == 1) {
							grid[i - 1][j] = currentChange + 1;
							++tempTotal;
						}
						if (i < grid.size() - 1 && grid[i + 1][j] == 1) {
							grid[i + 1][j] = currentChange + 1;
							++tempTotal;
						}
						if (j > 0 && grid[i][j - 1] == 1) {
							grid[i][j - 1] = currentChange + 1;
							++tempTotal;
						}
						if (j < grid[0].size() - 1 && grid[i][j + 1] == 1) {
							grid[i][j + 1] = currentChange + 1;
							++tempTotal;
						}
						grid[i][j] = 0;
					}
				}
			}

			if (tempTotal == total) return -1;
			total = tempTotal;
			++currentChange;
		}

		return static_cast<int>(minutes);
	}
};

int main() {
	{
		std::vector<std::vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
		std::cout << Solution().orangesRotting(grid) << std::endl << 4 << std::endl << std::endl;
	}

	{
		std::vector<std::vector<int>> grid = {{0, 2}};
		std::cout << Solution().orangesRotting(grid) << std::endl << 0 << std::endl << std::endl;
	}
}