#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int dp[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a;
	cin >> a;

	dp[1] = 3;
	dp[2] = 7;
	dp[3] = 17;

	for (int i = 4; i <= a; i++)
	{
		dp[i] = ((dp[i - 1] * 2) + dp[i - 2]) % 9901;
	}

	cout << dp[a];
}

