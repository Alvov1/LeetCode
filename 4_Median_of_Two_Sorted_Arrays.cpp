#include <iostream>

class Solution {
	int findKthElement(const std::vector<int>& first, const std::size_t firstIdx,
	          const std::vector<int>& second, const std::size_t secondIdx, const std::size_t requiredIdx) {
		/* 1. Check bounds. */
		if (firstIdx >= first.size())
			return second[secondIdx + requiredIdx - 1];
		else if (secondIdx >= second.size())
			return first[firstIdx + requiredIdx - 1];
		else if (requiredIdx == 1)
			return std::min(first[firstIdx], second[secondIdx]);

		/* 2. Find pivot, theoretical index of the left and the right elements. */
		const auto pivot = static_cast<std::size_t>(requiredIdx / 2),
			leftIdx = firstIdx + pivot - 1,
			rightIdx = secondIdx + pivot - 1,
			shiftIdx = requiredIdx - pivot;

		/* 3. Take value. If out of bounds, take MAX. */
		const auto left = leftIdx < first.size() ? first[leftIdx] : std::numeric_limits<int>::max(),
			right = rightIdx < second.size() ? second[rightIdx] : std::numeric_limits<int>::max();

		/* 4. Recall. */
		if (left < right)
			return findKthElement(
				first, firstIdx + pivot,
				second, secondIdx,
				shiftIdx);
		return findKthElement(
			first, firstIdx,
			second, secondIdx + pivot,
			shiftIdx);
	}

public:
	double findMedianSortedArrays(const std::vector<int>& first,
	                              const std::vector<int>& second) {
		const auto a = findKthElement(
			first, 0,
			second, 0,
			(first.size() + second.size() + 1) / 2);

		const auto b = findKthElement(
			first, 0,
			second, 0,
			(first.size() + second.size() + 2) / 2);

		return (a + b) / 2.0;
	}
};

int main() {
	{
		const std::vector<int> nums1 = {1,3}, nums2 = {2};
		std::cout << Solution().findMedianSortedArrays(nums1, nums2) << std::endl << 2.00000 << std::endl << std::endl;
	}
	{
		const std::vector<int> nums1 = {1,2}, nums2 = {3,4};
		std::cout << Solution().findMedianSortedArrays(nums1, nums2) << std::endl << 2.50000 << std::endl << std::endl;
	}
}
