#include <iostream>

class Solution {
public:
	bool isPalindrome(int x){
		if(x < 0)
			return false;
		if(x > 9 && x < 100)
			if(x % 10 == x / 10)
				return true;
			else
				return false;

		int dimension = 0;

		for(int i = 0; pow(10, i) <= abs(x); i++)
			dimension++;

		int i = 1;
		for(i; i <= dimension / 2; i++) {
			int c = x % int(pow(10, i));
			int d = int(pow(10, i - 1));

			int a = c / d;

			int m = (x / pow(10, dimension - i));
			int n = 10;
			int b = m % n;
			if(a != b)
				return false;
		}
		if (i == dimension / 2 + 1)
			return true;
		return false;
	}
};