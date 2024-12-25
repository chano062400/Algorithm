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
using namespace std;

bool dfs(int cur, int prev, const vector<vector<int>>& adj, vector<bool>& visited)
{
	visited[cur] = true;

	for (int next : adj[cur])
	{
		// 바로 이전에 탐색한 정점은 무시(양방향이기 때문에.)
		if (next == prev) continue;

		// 사이클 발견.
		if (visited[next]) return false;
		if (!dfs(next, cur, adj, visited)) return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);	
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int cnt = 0;
	while (++cnt)
	{
		int n, m, res = 0;
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		
		vector<vector<int>> adj(n + 1);
		vector<bool> visited(n + 1, 0);

		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				res += dfs(i, 0, adj, visited);
			}
		}

		if (res == 0)
		{
			cout << "Case " << cnt << ": No trees." << '\n';
		}
		else if (res == 1)
		{
			cout << "Case " << cnt << ": There is one tree." << '\n';
		}
		else
		{
			cout << "Case " << cnt << ": A forest of " << res << " trees." << '\n';
		}
	}
}


