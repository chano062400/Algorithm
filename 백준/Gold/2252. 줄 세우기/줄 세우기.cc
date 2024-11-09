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

void solve(const vector<vector<int>>& out, vector<int>& in, vector<bool>& check)
{
	queue<int> q;
	for (int i =1; i < in.size(); i++)
	{
		if (in[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		if (!check[cur])
		{
			check[cur] = true;
			cout << cur << " ";
		}
		q.pop();

		for (int i = 0; i < out[cur].size(); i++)
		{
			int next = out[cur][i];
			if (--in[next] == 0)
			{
				if (out[next].size() > 0)
				{
					q.push(next);
				}
				if (!check[next])
				{
					check[next] = true;
					cout << next << " ";
				}
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
	vector<vector<int>> out(n+1);
	vector<int> in(n + 1, 0);
	vector<bool> check(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		out[a].push_back(b);
		in[b]++;
	}

	for (int i = 1; i <= n; i++)
	{
		sort(out[i].begin(), out[i].end());
	}

	solve(out, in, check);

}