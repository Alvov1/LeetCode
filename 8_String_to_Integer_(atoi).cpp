#include <iostream>

int myAtoi(char * s){
	int len = strlen(s);

	long long int res = 0;
	int flag = 1;
	for(int i = 0; i < len; i++){
		if(s[i] != 32 && s[i] != '-' && s[i] != '+' && (s[i] <= 47 || s[i] >= 58))
			return 0;
		if(s[i] == '-') {
			if(s[i + 1] <= 47 || s[i + 1] >= 58)
				return 0;
			flag = -1;
		}

		if(s[i] == '+') {
			if(s[i + 1] <= 47 || s[i + 1] >= 58)
				return 0;
			flag = 1;
		}

		if(s[i] > 47 && s[i] < 58) {
			while (s[i] > 47 && s[i] < 58) {
				if((LLONG_MAX - s[i] + 48) / 10 > res) {
					res *= 10;
					res += (s[i] - 48);
				}
				else
					if(flag == 1)
						return INT_MAX;
					else
						return INT_MIN;
				i++;
			}
			break;
		}

	}

	if(res <= INT_MAX)
		return res * flag;
	else
		if(flag == 1)
			return INT_MAX;
		else
			return INT_MIN;
}