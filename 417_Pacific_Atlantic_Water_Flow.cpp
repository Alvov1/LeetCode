#include <iostream>

static constexpr std::size_t Atlantic = 7, Pacific = 9;

class Solution {
    std::size_t iMax, jMax;

    using Set = std::pair<bool, bool>;
    std::vector<std::vector<Set>> labels;

    /* This function does basic SET UNITE operation and returns true if new values added. */
    static bool uniteLabels(Set& addingTo, const Set& labelsAdding) {
        auto& [leftTo, rightTo] = addingTo;
        auto [leftAdding, rightAdding] = labelsAdding;

        bool count = false;
        if (leftAdding && !leftTo) {
            leftTo = true;
            count = true;
        }

        if (rightAdding && !rightTo) {
            rightTo = true;
            count = true;
        }

        return count;
    }

    void backtracking(std::vector<std::vector<int>>& grid,
        const std::size_t i,
        const std::size_t j) {

        const auto valueHere = grid[i][j];
        const auto labelsHere = labels[i][j];

        if (i + 1 < iMax && grid[i + 1][j] >= valueHere && uniteLabels(labels[i + 1][j], labelsHere))
            backtracking(grid, i + 1, j);

        if (j + 1 < jMax && grid[i][j + 1] >= valueHere && uniteLabels(labels[i][j + 1], labelsHere))
            backtracking(grid, i, j + 1);

        if (i > 0 && grid[i - 1][j] >= valueHere && uniteLabels(labels[i - 1][j], labelsHere))
            backtracking(grid, i - 1, j);

        if (j > 0 && grid[i][j - 1] >= valueHere && uniteLabels(labels[i][j - 1], labelsHere))
            backtracking(grid, i, j - 1);
    }

public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
        iMax = heights.size(), jMax = heights[0].size();

        labels = std::vector (iMax, std::vector (jMax, Set {}));
        constexpr Set atlantic = { false, true }, pacific = { true, false };

        // Initialize all atlantic cells
        for (std::size_t i = 0; i < iMax; i++)
            uniteLabels(labels[i][jMax - 1], atlantic);
        for (std::size_t j = 0; j < jMax; j++)
            uniteLabels(labels[iMax - 1][j], atlantic);

        // Initialize all pacific cells
        for (std::size_t i = 0; i < iMax; i++)
            uniteLabels(labels[i][0], pacific);
        for (std::size_t j = 0; j < jMax; j++)
            uniteLabels(labels[0][j], pacific);

        // Backtrack all atlantic cells
        for (std::size_t i = 0; i < iMax; i++)
            backtracking(heights, i, jMax - 1);
        for (std::size_t j = 0; j < jMax; j++)
            backtracking(heights, iMax - 1, j);

        // Backtrack all pacific cells
        for (std::size_t i = 0; i < iMax; i++)
            backtracking(heights, i, 0);
        for (std::size_t j = 0; j < jMax; j++)
            backtracking(heights, 0, j);

        heights.clear();

        for (int i = 0; i < iMax; i++) {
            for (int j = 0; j < jMax; j++) {
                if (labels[i][j].first && labels[i][j].second)
                    heights.push_back({i, j});
            }
        }

        return heights;
    }
};