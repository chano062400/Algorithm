#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>
#include "memory.h"
#include <map>
#include <string>
#include <iomanip>
#include <set>
using namespace std;

int t, n, k, target;
bool visited[1001];
int spend[1001], dp[1001];
vector<int> v[1001];


int dfs(int start)
{
	int dist = 0;

	if (dp[start] != -1) return dp[start];

	for (int i = 0; i < v[start].size(); i++)
	{
		int next = v[start][i];
		if (!visited[next])
		{
			dp[next] = dfs(next);
		}
		dist = max(dist, dp[next]);
	}

	return dist + spend[start];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		memset(visited, 0, sizeof(visited));
		memset(v, 0, sizeof(v));
		memset(spend, 0, sizeof(spend));
		memset(dp, -1, sizeof(dp));

		cin >> n >> k;

		for (int i = 1; i <= n; i++)
		{
			cin >> spend[i];
		}

		for (int i = 0; i < k; i++)
		{
			int from, to;
			cin >> from >> to;
			v[to].push_back(from);
		}
		
		cin >> target;
		

		cout << dfs(target) << '\n';
		
	}

}
	
