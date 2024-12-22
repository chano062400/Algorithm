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

bool visited[2000001];
int n;

void dfs(int idx, int sum, const vector<int>& v)
{
	if (idx == n)
	{
		visited[sum] = true;
		return;
	}

	dfs(idx + 1, sum, v);

	dfs(idx + 1, sum + v[idx], v);

}

int main()
{
	ios::sync_with_stdio(false);	
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		visited[v[i]] = true;
	}

	dfs(0, 0, v);

	for (int i = 1; i <= 2000000; i++)
	{
		if (!visited[i])
		{
			cout << i;
			return 0;
		}
	}
}

