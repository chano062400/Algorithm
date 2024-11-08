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
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

struct info
{
	int x, y, dist;
};

void getloc(int n, int m, int dir, int loc, int& x, int& y, vector<vector<int>>& v)
{
	if (dir == 1) v[0][loc] = dir, x = 0, y = loc;
	else if (dir == 2) v[n][loc] = dir, x = n, y = loc;
	else if (dir == 3) v[loc][0] = dir, x = loc, y = 0;
	else v[loc][m] = dir, x = loc, y = m;
}

bool cango(int nx, int ny, const vector<vector<int>>& v)
{
	return ((nx == 0 || nx == v.size() - 1) && (ny >= 0 && ny <= v[0].size() - 1)) || ((ny == 0 || ny == v[0].size() - 1) && (nx >= 0 && nx <= v.size() - 1));
}

void bfs(int x, int y, const vector<vector<int>>& v, vector<vector<int>>& dist)
{
	queue<info> q;
	q.push({ x,y,0 });
	dist[x][y] = 0;

	while (!q.empty())
	{
		int cx = q.front().x;
		int cy = q.front().y;
		int cdist = q.front().dist;
		q.pop();

		if (dist[cx][cy] < cdist) continue;

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int ndist = dist[cx][cy] + 1;
			if (cango(nx,ny,v))
			{
				if (dist[nx][ny] > ndist)
				{
					dist[nx][ny] = ndist;
					q.push({ nx,ny,ndist });
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
	cout.tie(nullptr);
	
	int m, n;
	cin >> m >> n;

	int store;
	cin >> store;

	vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> dist(n + 1, vector<int>(m + 1, 987654321));
	vector<pair<int, int>> pos;
	while (store--)
	{
		int dir, loc, x, y;
		cin >> dir >> loc;
		getloc(n, m, dir, loc, x, y, v);
		pos.push_back({ x,y });
	}

	int dir, loc, x, y;
	cin >> dir >> loc;
	getloc(n, m, dir, loc, x, y, v);
	v[x][y] = -1;

	bfs(x, y, v, dist);

	int res = 0;
	for (auto xy : pos)
	{
		res += dist[xy.first][xy.second];
	}

	cout << res;
}