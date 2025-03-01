#include <iostream>

class Solution {
public:
	int trap(std::vector<int>& height) {
		int total = 0;

		/* For each position we're going to find maximum left axe,
		 * and maximum right axe.
		 *
		 * Then would calculate maximum water level by taking min(axeL, axeR)
		 *
		 * And then we're going to subtract current height from the water level to get
		 * water amount
		 */
		for (int i = 0; i < height.size(); i++) {

			/* Finding max left AXE */
			int axeL = 0;
			for (int j = i - 1; j >= 0; j--) {
				axeL = std::max(axeL, height[j]);
			}

			/* Finding max right AXE */
			int axeR = 0;
			for (int j = i + 1; j < height.size(); j++) {
				if (axeR > axeL)
					break;
				axeR = std::max(axeR, height[j]);
			}

			const auto volume = std::min(axeL, axeR) - height[i];
			if (volume > 0)
				total += volume;
		}

		return total;
	}
};

int main() {

}