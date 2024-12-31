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

int arr[101][101][101];
bool visited[101][101][101];

int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
int m, n, h, total;
vector<pos> tomato1;
vector<pos> tomato0;

int bfs()
{
	queue<pos> q;
	for (pos pos : tomato1)
	{
		q.push({ pos.x, pos.y, pos.z});
		visited[pos.x][pos.y][pos.z] = true;
	}

	int days = 0;

	while (!q.empty())
	{
		days++;
		int size = q.size();
		for (int i = 0; i < size; i++)
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
				if (arr[nx][ny][nz] != 0 || visited[nx][ny][nz]) continue;

				visited[nx][ny][nz];
				arr[nx][ny][nz] = 1;
				tomato1.push_back({ nx,ny,nz });
				q.push({ nx,ny,nz });
			}
		}
		if (tomato1.size() == total)
		{
			return days;
		}
	}
	
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> m >> n >> h;
	
	for (int k = 1; k <= h; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1)
				{
					tomato1.push_back({ i,j,k });
				}
				else if (arr[i][j][k] == 0)
				{
					tomato0.push_back({ i,j,k });
				}
			}
		}
	}

	total = tomato0.size() + tomato1.size();
	if (tomato1.size() == total)
	{
		cout << 0;
		return 0;
	}
	else
	{
		cout << bfs();
	}
}


