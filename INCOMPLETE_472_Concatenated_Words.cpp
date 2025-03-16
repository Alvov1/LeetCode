#include <iostream>

class Solution {
public:
	std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string>& words) {

	}
};

int main() {
	{
		std::vector<std::string> data = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"},
			requiredOut = {"catsdogcats","dogcatsdog","ratcatdogcat"};
		const auto result = Solution().findAllConcatenatedWordsInADict(data);
		for (auto& w: result)
			std::cout << w << ' ';
		std::cout << std::endl;
		for (auto& w: requiredOut)
			std::cout << w << ' ';
		std::cout << std::endl << std::endl;
	}
	{
		std::vector<std::string> data = {"cat","dog","catdog"},
			requiredOut = {"catdog"};
		const auto result = Solution().findAllConcatenatedWordsInADict(data);
		for (auto& w: result)
			std::cout << w << ' ';
		std::cout << std::endl;
		for (auto& w: requiredOut)
			std::cout << w << ' ';
		std::cout << std::endl << std::endl;
	}
}