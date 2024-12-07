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

void bfs(const vector<vector<int>>& out, vector<int>& in, vector<int>& Time, vector<int>& res)
{
	queue<int> q;
	for (int i = 1; i < out.size(); i++)
	{
		if (in[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < out[cur].size(); i++)
		{
			int next = out[cur][i];
			res[next] = max(res[next], res[cur] + Time[cur]);
			if (--in[next] == 0)
			{
				q.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> out(n + 1);
	vector<int> Time(n + 1, 0);
	vector<int> in(n + 1, 0);
	vector<int> res(n + 1, 0);
	int idx = 1;
	for(int i = 1; i <= n; i++)
	{
		int cost;
		cin >> cost;
		Time[i] = cost;
		int num;
		while (1)
		{
			cin >> num;
			if (num == -1) break;
			out[num].push_back(i);
			in[i]++;
		}
	}
	
	bfs(out, in, Time, res);

	for (int i = 1; i <= n; i++)
	{
		cout << res[i] + Time[i] << '\n';
	}
}

