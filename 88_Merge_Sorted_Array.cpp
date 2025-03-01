#include <iostream>

class Solution {
public:
	void merge(std::vector<int>& numsA, int m, std::vector<int>& numsB, int n) {
		std::vector<int> buffer; buffer.reserve(m + n);
		unsigned posA = 0;
		unsigned posB = 0;
		while(posA < m && posB < n) {
			if(numsA[posA] < numsB[posB])
				buffer.push_back(numsA[posA++]);
			else
				buffer.push_back(numsB[posB++]);
		}
		for(; posA < m; ++posA)
			buffer.push_back(numsA[posA]);
		for(; posB < n; ++posB)
			buffer.push_back(numsB[posB]);
		numsA = buffer;
	}
};