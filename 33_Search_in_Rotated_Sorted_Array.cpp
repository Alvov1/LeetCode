#include <iostream>

class Solution {
	static int search(std::vector<int>::const_iterator start,
		const std::vector<int>::const_iterator end,
		const int X) {
		/* Small array. Checking by O(N). */
		const auto distance = std::distance(start, end);
		if (distance <= 3) {
			for (int i = 0; i < std::distance(start, end); i++)
				if (*(start + i) == X) return i;
			return -1;
		}

		/* Moving borders. */
		const auto midIdx = std::distance(start, end) / 2;
		const auto midIt = start + midIdx;
		const auto A = *start, B = *midIt, C = *(end - 1);

		if (A == X)
			return 0;
		if (B == X)
			return static_cast<int>(midIdx);
		if (C == X)
			return static_cast<int>(std::distance(start, end) - 1);

		// { { 4, 5, 6, 7, 0, 1, 2 }, 0 },
		// { { 6, 7, 0, 1, 2, 4, 5 }, 0 },
		// { { 7, 0, 1, 2, 4, 5, 6 }, 0 },

		// Если промежуток упорядоченный (R > L), то точно туда
		// Если больше обеих границ, то тоже туда

		// (L < X < R) || (X > L && X > R) || (X < R)
		const auto leftInOrder = A < X && X < B, rightInOrder = B < X && X < C;
		if ((A < X && X < B) || (A > B && (X > A || X < B))) {
			return search(start, midIt + 1, X);
		} else {
			const auto idx = search(midIt, end, X);
			if (idx != -1)
				return idx + static_cast<int>(std::distance(start, midIt));
			return idx;
		}
	}
	
public:
	static int search(const std::vector<int>& nums, int target) {
		return search(nums.begin(), nums.end(), target);
	}
};