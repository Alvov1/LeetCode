#include <iostream>

using KeyType = uint64_t;

KeyType toKey(int X, int Y) {
	const auto l = static_cast<KeyType>(X),
		r = static_cast<KeyType>(Y) << 32;
	return l | r;
}

void fromKey(KeyType data, int& X, int& Y) {
	X = static_cast<int>(data);
	Y = static_cast<int>(data >> 32);
}

class Solution {
	std::unordered_map<KeyType, bool> table { 510 };

public:
	int minAreaRect(std::vector<std::vector<int>>& points) {
        for (auto& coordinates : points)
        	table[toKey(coordinates[0], coordinates[1])] = true;

		int smallerArea = std::numeric_limits<int>::max();
		for (auto & i : table) {
			for (auto & j : table) {
				int lX, lY, rX, rY;
				fromKey(i.first, lX, lY);
				fromKey(j.first, rX, rY);

				if (table.contains(toKey(lX, rY)) && table.contains(toKey(rX, lY))) {
					const auto tArea = std::abs(rX - lX) * std::abs(rY - lY);
					if (tArea > 0 && tArea < smallerArea)
						smallerArea = tArea;
				}
			}
		}

		if (smallerArea != std::numeric_limits<int>::max())
			return smallerArea;
		return 0;
	}
};

int main() {
	Solution v {};
	std::cout << std::endl;
}