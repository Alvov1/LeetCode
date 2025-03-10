#include <iostream>

class Solution {
public:
	std::vector<int> partitionLabels(std::string s) {
		std::unordered_map<char, std::pair<std::size_t, std::size_t>> map {};

		for (std::size_t i = 0; i < s.size(); ++i) {
			if (const auto sym = s[i]; !map.contains(sym)) {
				map[sym] = { i, i };
			} else {
				map[sym].second = i;
			}
		}

		int last = 0;
		std::vector<int> partitions {};

		for (int i = last; i < s.size() - 1; ++i) {
			bool found = false;

			for (auto [_, borders]: map) {
				auto [start, end] = borders;
				if (i >= start && i < end) found = true;
			}

			if (found == false) {
				partitions.push_back(i + 1 - last);
				last = i + 1;
			}
		}

		partitions.push_back(static_cast<int>(s.size()) - last);

		return partitions;
	}
};

int main() {
	{
		const auto result = Solution().partitionLabels("ababcbacadefegdehijhklij");
		for (auto i : result)
			std::cout << i << ' ';
		std::cout << std::endl;
		for (auto i : {9, 7, 8})
			std::cout << i << ' ';
		std::cout << std::endl << std::endl;
	}

	{
		const auto result = Solution().partitionLabels("eccbbbbdec");
		for (auto i : result)
			std::cout << i << ' ';
		std::cout << std::endl;
		for (auto i : {10})
			std::cout << i << ' ';
		std::cout << std::endl << std::endl;
	}

	{
		const auto result = Solution().partitionLabels("caedbdedda");
		for (auto i : result)
			std::cout << i << ' ';
		std::cout << std::endl;
		for (auto i : {1, 9})
			std::cout << i << ' ';
		std::cout << std::endl << std::endl;
	}
}
