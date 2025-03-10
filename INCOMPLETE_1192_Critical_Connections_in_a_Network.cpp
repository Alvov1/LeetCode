#include <iostream>

class Solution {
public:
	std::vector<std::vector<int>> criticalConnections(int n, const std::vector<std::vector<int>>& connections) {

	}
};

int main() {
	{
		const std::vector<std::vector<int>> connections = { {0,1}, {1,2}, {2,0}, {1,3} },
		   desiredOutput = { {1,3} };
		for (auto& v: desiredOutput)
			std::cout << "[ " << v[0] << ", " << v[1] << "], " << std::endl;
		std::cout << std::endl;
		for (auto& v: Solution().criticalConnections(4, connections))
			std::cout << "[ " << v[0] << ", " << v[1] << "], " << std::endl;
		std::cout << std::endl << std::endl;

	}

	{
		const std::vector<std::vector<int>> connections = { {0,1} },
			desiredOutput = { {0,1} };
		for (auto& v: desiredOutput)
			std::cout << "[ " << v[0] << ", " << v[1] << "], " << std::endl;
		std::cout << std::endl;
		for (auto& v: Solution().criticalConnections(2, connections))
			std::cout << "[ " << v[0] << ", " << v[1] << "], " << std::endl;
		std::cout << std::endl << std::endl;
	}
}