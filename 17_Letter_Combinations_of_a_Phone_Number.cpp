#include <iostream>
#include <unordered_set>

/* Very basic backtracking task. Proud of doing it completely by myself. */

class Solution {
public:
	std::vector<std::string> letterCombinations(const std::string& digits) {
		if (digits.empty()) return {};

		static const std::unordered_map<char, std::vector<char>> dict = {
			{'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}}, {'4', {'g', 'h', 'i'}},
			{'5', {'j', 'k', 'l'}}, {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
			{'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}
		};

		std::vector<std::string> result {};

		std::string chars {};
		chars.reserve(digits.size());
		chars.push_back(dict.at(digits[0])[0]);

		std::vector<int8_t> indexes {};
		indexes.reserve(digits.size());
		indexes.push_back(0);

		while (!chars.empty()) {
			if (chars.size() >= digits.size()) {
				result.push_back(chars);

				int8_t currentIdx {};
				do {
					currentIdx = indexes.back() + 1;
					indexes.pop_back();
					chars.pop_back();

					const auto currentKey = digits[chars.size()];

					const auto& variants = dict.at(currentKey);
					if (currentIdx < variants.size()) break;
				} while (!chars.empty());

				const auto currentKey = digits[chars.size()];
				const auto& variants = dict.at(currentKey);
				if (currentIdx < variants.size() || !chars.empty()) {
					chars.push_back(variants[currentIdx]);
					indexes.push_back(currentIdx);
				}
			} else {
				const auto& variants = dict.at(digits[chars.size()]);
				chars.push_back(variants[0]);
				indexes.push_back(0);
			}
		}

		return result;
	}
};

int main() {
	{
		const std::string data = "23";
		const std::vector required = {"ad","ae","af","bd","be","bf","cd","ce","cf"};
		const auto v = Solution().letterCombinations(data);
		for (auto& vv: v)
			std::cout << vv << ' ';
		std::cout << std::endl;
		for (auto& vv: required)
			std::cout << vv << ' ';
		std::cout << std::endl << std::endl;
	}

	{
		const std::string data {};
		const std::vector<std::string> required = {};
		const auto v = Solution().letterCombinations(data);
		for (auto& vv: v)
			std::cout << vv << ' ';
		std::cout << std::endl;
		for (auto& vv: required)
			std::cout << vv << ' ';
		std::cout << std::endl << std::endl;
	}

	{
		const std::string data = "2";
		const std::vector required = {"a","b","c"};
		const auto v = Solution().letterCombinations(data);
		for (auto& vv: v)
			std::cout << vv << ' ';
		std::cout << std::endl;
		for (auto& vv: required)
			std::cout << vv << ' ';
		std::cout << std::endl << std::endl;
	}
}