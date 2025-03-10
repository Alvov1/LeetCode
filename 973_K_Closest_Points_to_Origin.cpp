#include <iostream>

class Solution {
public:
	std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
		std::sort(points.begin(), points.end(),
		[](const auto& a, const auto& b) {
			return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
		});

		std::vector<std::vector<int>> result {};
		result.reserve(k);
		for (std::size_t i = 0; i < k; ++i)
			result.push_back(points[i]);
		return result;
	}
};

int main() {
	{
		std::vector<std::vector<int>> values = { {1,3}, {-2,2} },
		   desiredOutput = { {-2,2} };
		for (auto& v: Solution().kClosest(values, 1))
			std::cout << "[ " << v[0] << ", " << v[1] << "], ";
		std::cout << std::endl;
		for (auto& v: desiredOutput)
			std::cout << "[ " << v[0] << ", " << v[1] << "], ";
		std::cout << std::endl << std::endl;
	}

	{
		std::vector<std::vector<int>> values = { {3,3}, {5,-1}, {-2,4} },
		   desiredOutput = { {3,3}, {-2,4} };
		for (auto& v: Solution().kClosest(values, 2))
			std::cout << "[ " << v[0] << ", " << v[1] << "], ";
		std::cout << std::endl;
		for (auto& v: desiredOutput)
			std::cout << "[ " << v[0] << ", " << v[1] << "], ";
		std::cout << std::endl << std::endl;
	}

}