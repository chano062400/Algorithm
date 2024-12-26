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

#define MAX 987654321

int bfs(vector<int>& in, const vector<vector<int>>& out, const vector<int>& cost, vector<int>& time)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int res = 0;

	for (int i = 1; i < in.size(); i++)
	{
		if (in[i] == 0)
		{
			pq.push({ cost[i], i });
			res = max(res, cost[i]);
		}
	}

	while (!pq.empty())
	{
		int start = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		

		for (int i = 0; i < out[cur].size(); i++)
		{
			int next = out[cur][i];

			if (--in[next] == 0)
			{
				res = max(res, start + cost[next]);
				pq.push({ start + cost[next], next});
			}
		}
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(false);	
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	cin >> n;

	vector<int> in(n + 1, 0), cost(n + 1, 0), time(n + 1, MAX);
	vector<vector<int>> out(n + 1);

	for (int i = 1; i <= n; i++)
	{
		int t, k;
		cin >> t >> k;	
		
		cost[i] = t;

		if (k == 0) continue;
		while (k--)
		{
			int job;
			cin >> job;
			in[i]++;
			out[job].push_back(i);
		}
	}

	cout <<	bfs(in, out, cost, time);

}


