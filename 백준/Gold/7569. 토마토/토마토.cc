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

struct pos
{
	int x, y, z;
};

int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
int m, n, h;

int bfs(vector<vector<vector<int>>>& arr)
{
	queue<pos> q;

	for (int k = 1; k <= h; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (arr[i][j][k] == 1)
				{
					q.push({ i,j,k });
				}
			}
		}
	}

	while (!q.empty())
	{
		int cx = q.front().x;
		int cy = q.front().y;
		int cz = q.front().z;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nz = cz + dz[i];

			if (nx < 1 || nx > n || ny < 1 || ny > m || nz < 1 || nz > h) continue;
			if (arr[nx][ny][nz] != 0) continue;

			arr[nx][ny][nz] = arr[cx][cy][cz] + 1;
			q.push({ nx,ny,nz });
		}
	}
	
	int res = 0;
	for (int k = 1; k <= h; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (arr[i][j][k] == 0) return -1;
				res = max(res, arr[i][j][k]);
			}
		}
	}

	return res - 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> m >> n >> h;
	
	vector<vector<vector<int>>> arr(n + 1, vector<vector<int>>(m + 1, vector<int>(h + 1, 0)));

	for (int k = 1; k <= h; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> arr[i][j][k];
			}
		}
	}

	cout << bfs(arr);
}


