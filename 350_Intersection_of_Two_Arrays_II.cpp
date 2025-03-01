#include <iostream>
#include <set>

class Solution {
public:
	std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
		std::vector<int> data(nums1.size() + nums2.size());

		std::multiset<int> ms1 (nums1.begin(), nums1.end());
		std::multiset<int> ms2 (nums2.begin(), nums2.end());

		auto end = std::set_intersection( ms1.begin(), ms1.end(), ms2.begin(), ms2.end(), data.begin() );
		return { data.begin(), end };
	}
};