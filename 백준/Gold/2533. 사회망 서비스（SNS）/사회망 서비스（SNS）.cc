#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
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
#include <list>
using namespace std;

int n, cnt, res;

void dfs(int cur, const vector<vector<int>>& v, vector<bool>& visited, vector<vector<int>>& dp)
{
	visited[cur] = true;
	// 본인이 얼리어답터가 아닌 경우.
	dp[cur][0] = 0;
	
	// 본인이 얼리어답터인 경우.
	dp[cur][1] = 1;

	for (int i = 0; i < v[cur].size(); i++)
	{
		int next = v[cur][i];
		if (visited[next]) continue;

		dfs(next, v, visited, dp);

		// 본인이 얼리어답터가 아니라면 주변 친구들이 모두 얼리어답터여야 함.
		dp[cur][0] += dp[next][1];
		
		// 본인이 얼리어답터라면 주변은 얼리어답터든 아니든 상관X.
		dp[cur][1] += min(dp[next][0], dp[next][1]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	cin >> n;
	vector<vector<int>> v(n + 1), dp(n + 1, vector<int>(2, 0));
	vector<bool> visited(n + 1, 0);


	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1, v, visited, dp);
 
	cout << min(dp[1][0], dp[1][1]);
}


