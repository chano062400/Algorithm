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
using namespace std;

int dp[101][10001];
int memory[101];
int cost[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
	cout.tie(nullptr);

	int n, m, sum = 0;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> memory[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
		sum += cost[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (j - cost[i] >= 0)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	for (int i = 0; i <= sum; i++)
	{
		if (dp[n][i] >= m)
		{
			cout << i;
			break;
		}
	}
}