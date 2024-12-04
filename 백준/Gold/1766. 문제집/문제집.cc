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

void bfs(vector<int>& in, vector<vector<int>>& out, vector<bool>& check)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i < in.size(); i++)
	{
		if (in[i] == 0)
		{
			pq.push(i);
		}
	}

	while (!pq.empty())
	{
		int cur = pq.top();
		pq.pop();

		cout << cur << " ";

		for (int i = 0; i < out[cur].size(); i++)
		{
			int next = out[cur][i];
			if (--in[next] == 0)
			{
				pq.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> out(n + 1);
	vector<int> in(n + 1, 0);
	vector<bool> check(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		out[a].push_back(b);
		in[b]++;
	}

	bfs(in, out, check);

}

