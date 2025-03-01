#include <iostream>

class Solution {
public:
	int minPathSum(std::vector<std::vector<int>>& grid) {
		const auto iMax = grid.size(), jMax = grid[0].size();

		for (int i = 0; i < iMax; ++i)
			for (int j = 0; j < jMax; ++j)
				if (i > 0 && j > 0) // For center cells adding minimum of upper and lefter cells
					grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
				else if (i > 0) // For cells to the left adding value of the upper cell
					grid[i][j] += grid[i - 1][0];
				else if (j > 0) // For cells at the upper level adding value of the left cell
					grid[i][j] += grid[0][j - 1];

		return grid[iMax - 1][jMax - 1];
	}
};