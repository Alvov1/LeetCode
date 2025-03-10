#include <iostream>
#include <unordered_map>

class Solution {
public:
	std::vector<std::string> reorderLogFiles(const std::vector<std::string>& logs) {
		std::vector<std::pair<std::string, std::string>> letterLogs {}; letterLogs.reserve(logs.size());
		std::vector<std::string> digitLogs {}; digitLogs.reserve(logs.size());

		for (auto& log: logs) {
			std::string id {};
			std::size_t pos = 0;
			for (; log[pos] != ' ' && pos < log.size(); ++pos)
				id += log[pos];
			if (std::isalpha(log[pos + 1]))
				letterLogs.emplace_back(id, log.substr(pos));
			else
				digitLogs.push_back(log);
		}

		std::sort(letterLogs.begin(), letterLogs.end(),
				[](const auto& a, const auto& b) {
					if (a.second != b.second)
						return a.second < b.second; // сначала по значению
					return a.first < b.first;       // если значения равны, по ключу
				});

		std::vector<std::string> result {}; result.reserve(letterLogs.size() + digitLogs.size());
		for (const auto& [id, data]: letterLogs)
			result.emplace_back(id + data);
		for (const auto& data: digitLogs)
			result.emplace_back(data);
		return result;
	}
};

int main() {
	{
		const std::vector<std::string> input = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"},
			desiredOutput = {"let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"};
		for (const auto & i : Solution().reorderLogFiles(desiredOutput))
			std::cout << "\"" << i << "\", ";
		std::cout << std::endl;
		for (const auto & i : desiredOutput)
			std::cout << "\"" << i << "\", ";
		std::cout << std::endl << std::endl;
	}

	{
		const std::vector<std::string> input = {"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"},
			desiredOutput = {"g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"};
		for (const auto & i : Solution().reorderLogFiles(desiredOutput))
			std::cout << "\"" << i << "\", ";
		std::cout << std::endl;
		for (const auto & i : desiredOutput)
			std::cout << "\"" << i << "\", ";
		std::cout << std::endl << std::endl;
	}

}