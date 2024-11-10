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
using namespace std;

struct info
{
	int from, to;
	long long dist;
};

bool bellmanford(int n, vector<info>& v, vector<long long>& dist)
{
	dist[1] = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			int from = v[j].from;
			int to = v[j].to;
			long long cost = v[j].dist;
			if (dist[from] == INT64_MAX) continue;
			if (dist[from] + cost < dist[to]) dist[to] = dist[from] + cost;
		}
	}

	// n - 1번 계산한 후 한번 더 진행했을 때, 거리가 더 줄어드는 노드가 있다면 음의 사이클이 존재하는 것.
	for(int i = 0; i<v.size(); i++)
	{
		int from = v[i].from;
		int to = v[i].to;
		long long cost = v[i].dist;
		if (dist[from] == INT64_MAX) continue;
		if (dist[from] + cost < dist[to])
		{
			cout << -1;
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

	int n, m;
	cin >> n >> m;
	
	vector<info> v;
	vector<long long> dist(n + 1, INT64_MAX);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}

	if (bellmanford(n, v, dist))
	{
		for (int i = 2; i <= n; i++)
		{
			dist[i] == INT64_MAX ? cout << -1 << '\n' : cout << dist[i] << '\n';
		}
	}
}