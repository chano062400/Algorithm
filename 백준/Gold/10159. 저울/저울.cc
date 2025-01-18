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

bool isheavy[101][101];
int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		isheavy[a][b] = 1;
	}

	for (int h = 1; h <= n; h++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j) continue;

				if (isheavy[i][h] && isheavy[h][j])
				{
					// i가 h보다 크고, h가 j보다 크다면 -> i는 j보다 큼.
					isheavy[i][j] = 1;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;

			// 둘의 비교 관계를 안다면
			if (isheavy[i][j] || isheavy[j][i])
			{
				cnt++;
			}
		}

		cout << n - 1 - cnt << '\n';
	}
}


