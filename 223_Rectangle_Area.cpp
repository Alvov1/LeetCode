#include <algorithm>

class Solution {
public:
	int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
		auto total = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);

		const auto width = std::min(ax2, bx2) - std::max(ax1, bx1);
		const auto height = std::min(ay2, by2) - std::max(ay1, by1);
		if (width > 0 && height > 0)
			total -= width * height;

		return total;
	}
};