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

int arr[20][20];
int dx[] = { 0,1,1,-1 };
int dy[] = { 1,0,1,1 };

bool isinrange(int x, int y)
{
	return x >= 1 && x <= 19 && y >= 1 && y <= 19;
}

void update(int x, int y, int& rx, int& ry, int k)
{
	if (k == 0)
	{
		ry = min(ry, y);
	}
	if (k == 1)
	{
		rx = min(rx, x);
	}
	else
	{
		if (y < ry)
		{
			rx = x;
			ry = y;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 19; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 19; j++)
		{
			if (arr[i][j] == 0) continue;

			for (int k = 0; k < 4; k++)
			{
				int x = i - dx[k], y = j - dy[k], cnt = 1, bw = arr[i][j], rx = i, ry = j;
				
				while (1)
				{
					int nx = x - dx[k];
					int ny = y - dy[k];
					if (arr[x][y] == bw && isinrange(x, y))
					{
						++cnt;
						if (arr[nx][ny] != bw || !isinrange(nx, ny)) break;
					}
					else break;
					x = nx;
					y = ny;
					update(x, y, rx, ry, k);
				}
				
				x = i + dx[k];
				y = j + dy[k];

				while (1)
				{
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (arr[x][y] == bw && isinrange(x, y))
					{
						++cnt;
						if (arr[nx][ny] != bw || !isinrange(nx, ny)) break;
					}
					else break;
					x = nx;
					y = ny;
					update(x, y, rx, ry, k);
				}

				if (cnt == 5)
				{
					cout << arr[i][j] << '\n';
					cout << rx << " " << ry;
					return 0;
				}
			}
		}
	}
	cout << 0;
}

