#include <iostream>

class Solution {
public:
	int reverse(int x) {
		int flag = (x < 0) ? -1 : 1;
		long long sum = 0;
		if(x != INT_MIN)
			sum = x * flag;
		else
			return 0;
		long long int temp = 0;

		while(sum != 0){
			temp *= 10;
			temp += sum % 10;
			sum /= 10;
		}

		if(temp > (pow(2, 31) - 1))
			return 0;
		else
			return temp * flag;
	}
};