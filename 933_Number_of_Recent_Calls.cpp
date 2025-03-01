#include <iostream>

class RecentCounter {
	std::vector<int> pings;
public:
	RecentCounter() = default;

	int ping(int t) {
		pings.push_back(t);
		if(t < 3001)
			return static_cast<int>(pings.size());
		return static_cast<int>(pings.size() - findNearestValue(t - 3000));
	}

	unsigned findNearestValue(int target) {
		unsigned start = 0;
		unsigned end = pings.size();

		unsigned ans = 0;
		while (start <= end) {
			unsigned mid = (start + end) / 2;

			if (pings[mid] > target) {
				if(mid == 0) return 0;
				ans = mid;
				end = mid - 1;
			} else if (pings[mid] < target)
				start = mid + 1;
			else
				return mid;
		}

		return ans;
	}
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */