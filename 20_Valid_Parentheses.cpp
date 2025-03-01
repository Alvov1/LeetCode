#include <iostream>

class Solution {
public:
	bool isValid(std::string s) {
		std::stack<char> stack;
		for(auto& ch: s) {
			if(ch == '(' || ch == '[' || ch == '{')
				stack.push(ch);
			else {
				if(ch == ')') {
					if (!stack.empty() && stack.top() == '(')
						stack.pop();
					else
						return false;
				}
				if(ch == ']') {
					if (!stack.empty() && stack.top() == '[')
						stack.pop();
					else
						return false;
				}
				if(ch == '}') {
					if (!stack.empty() && stack.top() == '{')
						stack.pop();
					else
						return false;
				}
			}
		}
		return stack.empty();
	}
};