#include <iostream>
#include <string>

class Solution {
public:
	std::string reverseWords(std::string s) {
		std::string result {};
		result.reserve(s.size());

		std::stack<std::string> stack {};

		for (std::size_t pos = 0; pos < s.size(); ) {
			/* 1. Skip leading spaces. */
			for (; s[pos] == ' ' && pos < s.size(); ++pos)
				;

			if (pos >= s.size())
				break;

			/* 2. Print word. */
			stack.emplace();
			for (; s[pos] != ' ' && pos < s.size(); ++pos)
				stack.top() += s[pos];
		}

		result += stack.top();
		stack.pop();

		while (!stack.empty()) {
			result += ' ';
			result += stack.top();
			stack.pop();
		}

		return result;
	}
};

int main() {
	std::cout << Solution().reverseWords("the sky is blue") << std::endl << "blue is sky the" << std::endl << std::endl;

	std::cout << Solution().reverseWords("  hello world  ") << std::endl << "world hello" << std::endl << std::endl;

	std::cout << Solution().reverseWords("a good   example") << std::endl << "example good a" << std::endl << std::endl;
}