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

#define MAX 987654321

struct info
{
	int from, to, dist;
};

bool bellmanford(int start, const vector<info>& v, vector<int>& dist)
{
	dist[start] = 0;
	for (int i = 1; i < dist.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			int from = v[j].from;
			int to = v[j].to;
			int cost = v[j].dist;
			if (dist[from] == MAX) continue;
			if (dist[from] + cost < dist[to])
			{
				dist[to] = dist[from] + cost;
			}
		}
	}

	for (int j = 0; j < v.size(); j++)
	{
		int from = v[j].from;
		int to = v[j].to;
		int cost = v[j].dist;
		if (dist[from] == MAX) continue;
		if (dist[from] + cost < dist[to])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);	
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	while (t--)
	{
		int n, m, w;
		cin >> n >> m >> w;

		vector<info> v, wh;
		vector<int> dist(n + 1, MAX);

		int s, e, t;
		for (int i = 0; i < m; i++)
		{
			cin >> s >> e >> t;
			v.push_back({ s, e, t });
			v.push_back({ e, s, t });
		}
		for (int i = 0; i < w; i++)
		{
			cin >> s >> e >> t;
			v.push_back({ s, e, -t });
		}

		for (int i = 1; i <= n; i++)
		{
			v.push_back({ 0, i, 0 });
		}

		if (!bellmanford(0, v, dist))
		{
			cout << "YES" << '\n';
		}
		else cout << "NO" << '\n';
	}

}

