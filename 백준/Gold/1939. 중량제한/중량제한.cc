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

int n, m;
vector<pair<int,int>> v[100001];
int weight[100001];


void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
	weight[start] = 1000000000;
	pq.push({ weight[start], start});

	while (!pq.empty())
	{
		int curweight = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		// 지금까지 구한 최대 무게보다 작다면 continue.
		if (weight[cur] > curweight) continue;

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i].first;
			int nextweight = min(curweight, v[cur][i].second);

			if (weight[next] < nextweight)
			{
				weight[next] = nextweight;
				pq.push({ weight[next], next });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	int n1, n2, res = 0;
	cin >> n1 >> n2;

	fill(weight, weight + n + 1, 0);
 	dijkstra(n1);
	 
	cout << weight[n2];
}


