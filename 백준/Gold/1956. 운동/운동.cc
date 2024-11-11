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

#define MAX 987654321

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1, vector<int>(n+1 ,MAX));

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a][b] = c;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (v[i][j] > v[i][k] + v[k][j])
				{
					v[i][j] = v[i][k] + v[k][j];
				}
			}
		}
	}

	int res = MAX;
	for (int i = 1; i <= n; i++)
	{
		res = min(res, v[i][i]);
	}
	res == MAX ? cout << -1 : cout << res;
}