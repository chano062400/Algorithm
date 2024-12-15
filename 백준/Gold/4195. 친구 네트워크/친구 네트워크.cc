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

int Find(int x, vector<int>& parent)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x], parent);
}

int Union(int x, int y, vector<int>& parent, vector<int>& rank)
{
	x = Find(x, parent);
	y = Find(y, parent);

	if (x == y) return rank[x];

	// x를 항상 큰 그룹으로 설정.
	if (rank[x] < rank[y])
	{
		swap(x, y);
	}

	parent[y] = x;

	// 병합. 자식 노드의 높이 만큼 부모 노드의 높이 증가.
	rank[x] += rank[y];

	return rank[x];
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
		int n, idx = 0;
		cin >> n;
	
		unordered_map<string, int> name;
		vector<int> parent(n * 2 + 1, 0);
		vector<int> rank(n * 2 + 1, 1);

		for (int i = 1; i <= n * 2; i++)
		{
			parent[i] = i;
		}

		for (int i = 0; i < n; i++)
		{
			string a, b;
			cin >> a >> b;
			if (name.find(a) == name.end())
			{
				name[a] = ++idx;
			}
			if (name.find(b) == name.end())
			{
				name[b] = ++idx;
			}

			cout << Union(name[a], name[b], parent, rank) << '\n';
		}
	}
}

