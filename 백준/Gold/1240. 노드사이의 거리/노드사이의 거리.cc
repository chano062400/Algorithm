#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include "memory.h"
#include <map>
#include <string>

using namespace std;

int n, m,res=0;
bool visited[10001];
vector<pair<int, int>> v[10001];

void dfs(int start, int target, int value)
{
	visited[start] = 1;

	if (start == target)
	{
		res = value;
		return;
	}
	for (int i = 0; i < v[start].size(); i++)
	{
		int next = v[start][i].first;
		int nextcost = value + v[start][i].second;

		if(!visited[next])
			dfs(next, target, nextcost);
	}
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
  
	cin >> n >> m;
	for (int i = 0; i < n-1; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back(make_pair(to, cost));
		v[to].push_back(make_pair(from, cost));
	}

	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;
		dfs(start, end, 0);
		cout << res << '\n';

		memset(visited, 0, sizeof(visited));
		res = 0;
	}

}
