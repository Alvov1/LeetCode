#include <iostream>

class Solution {
	static void backtracking(const std::vector<std::vector<char>>& grid,
			const std::size_t baseI,
			const std::size_t baseJ,
			std::vector<std::vector<bool>>& visited) {
		visited[baseI][baseJ] = true;

		std::vector<std::pair<std::size_t, std::size_t>> q {};
		q.reserve(9);
		q.emplace_back(baseI, baseJ);

		const auto iMax = grid.size(),
			jMax = grid[0].size();

		while (!q.empty()) {
			const auto [curI, curJ] = q.back();
			q.pop_back();

			if (curI + 1 < iMax && grid[curI + 1][curJ] == '1' && !visited[curI + 1][curJ]){
				q.emplace_back(curI + 1, curJ); //grid[i + 1][j]
				visited[curI + 1][curJ] = true;
			}

			if (curI > 0 && grid[curI - 1][curJ] == '1' && !visited[curI - 1][curJ]){
				q.emplace_back(curI - 1, curJ); //grid[i - 1][j]
				visited[curI - 1][curJ] = true;
			}

			if (curJ + 1 < jMax && grid[curI][curJ + 1] == '1' && !visited[curI][curJ + 1]){
				q.emplace_back(curI, curJ + 1); //grid[i][j + 1]
				visited[curI][curJ + 1] = true;
			}

			if (curJ > 0 && grid[curI][curJ - 1] == '1' && !visited[curI][curJ - 1]){
				q.emplace_back(curI, curJ - 1); //grid[i][j - 1]
				visited[curI][curJ - 1] = true;
			}
		}
	}

public:
	static int numIslands(const std::vector<std::vector<char>>& grid) {
		const auto iMax = grid.size(), jMax = grid[0].size();
		std::vector visited { iMax, std::vector(jMax, false) };

		int total = 0;
		for (std::size_t i = 0; i < iMax; ++i) {
			for (std::size_t j = 0; j < jMax; ++j) {
				if (!visited[i][j] && grid[i][j] == '1') {
					++total;
					backtracking(grid, i, j, visited);
				}
			}
		}
		return total;
	}
};