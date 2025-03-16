#include <iostream>

class Solution {
public:
	std::vector<std::string> topKFrequent(const std::vector<std::string>& words, int k) {
		std::unordered_map<std::string, std::size_t> mp {};
		for (auto& w : words)
			mp[w]++;

		std::vector<std::pair<std::string, int>> vec(mp.begin(), mp.end());

		std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
			if (a.second == b.second) {
				return a.first < b.first;
			} else return a.second > b.second;
		});

		std::vector<std::string> res (k);
		for (std::size_t i = 0; i < k; i++) {
			res[i] = vec[i].first;
		}
		return res;
	}
};

int main() {
	{
		std::vector<std::string> data = { "i","love","leetcode","i","love","coding" };
		const auto v = Solution().topKFrequent(data, 2);
		for (auto& vv: v)
			std::cout << vv << ", ";
		std::cout << std::endl;
		for (auto& vv: {"i","love"})
			std::cout << vv << ", ";
		std::cout << std::endl << std::endl;
	}
	{
		std::vector<std::string> data = {"the","day","is","sunny","the","the","the","sunny","is","is"};
		const auto v = Solution().topKFrequent(data, 4);
		for (auto& vv: v)
			std::cout << vv << ", ";
		std::cout << std::endl;
		for (auto& vv: {"the","is","sunny","day"})
			std::cout << vv << ", ";
	}
}