#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "memory.h"
#include <set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
#include <limits.h>
using namespace std;

#define MOD 1000000

int main()
{
	ios::sync_with_stdio(false);	
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;
	
	int len = str.length();

	if (str[0] == '0')
	{
		cout << 0;
		return 0;
	}

	vector<int> dp(len + 1, 0);
	dp[0] = dp[1] = 1;

	for (int i = 2; i <= len; i++)
	{
		if (str[i - 1] != '0')
		{
			dp[i] = dp[i - 1] % MOD;
		}

		int num = stoi(str.substr(i - 2, 2));
		if (num >= 10 && num <= 26)
		{
			dp[i] = (dp[i - 2] + dp[i]) % MOD;
		}
		
	}
	cout << dp[len];
}

