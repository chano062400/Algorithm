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

int n, m;
int in[1001];
vector<int> out[1001], res;
bool check[1001];

void solution()
{
	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		if (in[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		if (in[cur] == 0 && !check[cur])
		{
			check[cur] = true;
			res.push_back(cur);
		}
		q.pop();

		for (int i = 0; i < out[cur].size(); i++)
		{
			int next = out[cur][i];
			if (--in[next] == 0)
			{
				q.push(next);
				check[next] = true;
				res.push_back(next);
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
		int num, first, prev;
		cin >> num >> first;

		prev = first;
		for (int j = 1; j < num; j++)
		{
			int singer;
			cin >> singer;
			out[prev].push_back(singer);
			in[singer]++;
			prev = singer;
		}
	}

	solution();

	if (res.size() == n)
	{
		for (int num : res)
		{
			cout << num << '\n';
		}
	}
	else cout << 0;
}

