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

int population[11];
vector<int> v[11];
bool selected[11];
int n, res;

#define MAX 987654321

bool isconnected(const vector<int>& connect, bool flag)
{
	vector<bool> visited(n + 1, false);
	queue<int> q;
	
	visited[connect[0]] = true;
	q.push(connect[0]);

	int cnt = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int next : v[cur])
		{
			// 고르지 않은 구역이거나 이미 queue에 넣은 구역이라면 continue.
			if (selected[next] != flag || visited[next]) continue;
			
			visited[next] = true;
			++cnt;
			q.push(next);
		}
	}

	return connect.size() == cnt;
	
}

bool check()
{
	vector<int> a, b;

	for (int i = 1; i <= n; i++)
	{
		if (selected[i]) a.push_back(i);
		else b.push_back(i);
	}

	// 선택한 구역은 true, 선택하지 않은 구역은 false.
	if (a.empty() || b.empty() || !isconnected(a, true) || !isconnected(b, false)) return false;

	return true;
}

void dfs(int cur, int depth)
{
	// 모든 구역의 조합을 탐색.
	if (depth >= 1)
	{
		// 모든 구역들이 선거구에 포함돼있다면 인구 수 차이 계산.
		if (check())
		{
			int a = 0, b = 0;

			for (int i = 1; i <= n; i++)
			{
				if (selected[i]) a += population[i];
				else b += population[i];
			}

			res = min(res, abs(a - b));
		}
	}
	
	for (int i = cur; i <= n; i++)
	{
		if (!selected[i])
		{
			selected[i] = true;
			dfs(i + 1, depth + 1);
			selected[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);	
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
		
	for (int i = 1; i <= n; i++)
	{
		cin >> population[i];
	}

	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		while (a--)
		{
			int j;
			cin >> j;
			v[i].push_back(j);
			v[j].push_back(i);
		}
	}

	res = MAX;
	dfs(1, 0);
	
	res == MAX ? cout << -1 : cout << res;
}


