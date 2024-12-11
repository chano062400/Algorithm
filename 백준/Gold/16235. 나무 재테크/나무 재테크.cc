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

struct info
{
	int x, y, age;
};

int n, m, k;
int nutrient[11][11];
int add[11][11];
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
deque<int> trees[11][11];

void spring_summer(int x, int y)
{
	int idx = 0;
	for (; idx < trees[x][y].size(); idx++)
	{
		int age = trees[x][y][idx];
		if (age <= nutrient[x][y])
		{
			nutrient[x][y] -= age;
			trees[x][y][idx]++;
		}
		else break;
	}

	// 죽은 나무가 있다면
	if (idx < trees[x][y].size())
	{
		for (int i = trees[x][y].size() - 1; i >= idx; i--)
		{
			int age = trees[x][y][i];
			nutrient[x][y] += age / 2;
			// 양분으로 변환하고 pop_back().
			trees[x][y].pop_back();
		}
	}
}

void autumn()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if (trees[i][j].empty()) continue;

			for (int k = 0; k < trees[i][j].size(); k++)
			{
				if (trees[i][j][k] % 5 == 0)
				{
					for (int h = 0; h < 8; h++)
					{
						int nx = i + dx[h];
						int ny = j + dy[h];
						if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
						// 정렬 상태가 유지되도록 push_front().
						trees[nx][ny].push_front(1);
					}
				}
			}
		}
	}
}

void winter()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			nutrient[i][j] += add[i][j];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);	
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m >> k;
	for (int i = 0; i <= n; i++) 
	{
		for (int j = 0; j <= n; j++) 
		{
			nutrient[i][j] = 5;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> add[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;

		trees[x][y].push_back(z);
	}

	// 초기 정렬
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++) 
		{
			if (trees[i][j].empty()) continue;

			sort(trees[i][j].begin(), trees[i][j].end());
		}
	}

	while (k--)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (trees[i][j].size())
				{
					spring_summer(i, j);
				}
			}
		}

		autumn();

		winter();
	}

	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			res += trees[i][j].size();
		}
	}

	cout << res;
}

