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
bool visited[10][10][10][10];

struct pos
{
	int rx, ry, bx, by, cnt;
};

void rollblue(int& bx, int& by, int dir, bool& goalblue, vector<vector<char>>& v)
{
	while (1)
	{
		if (bx + dx[dir] < 0 || bx + dx[dir] >= v.size() || by + dy[dir] < 0 || by + dy[dir] >= v[0].size()) continue;
		bx += dx[dir];
		by += dy[dir];
		if (bx < 0 || bx >= v.size() || by < 0 || by >= v[0].size()) continue;
		if (v[bx][by] == 'O')
		{
			goalblue = true;
			break;
		}
		if (v[bx][by] == '#')
		{
			bx -= dx[dir];
			by -= dy[dir];
			break;
		}
	}
}

void rollred(int& rx, int& ry, int dir, bool& goalred, vector<vector<char>>& v)
{
	while (1)
	{
		if (rx + dx[dir] < 0 || rx + dx[dir] >= v.size() || ry + dy[dir] < 0 || ry + dy[dir] >= v[0].size()) continue;
		rx += dx[dir];
		ry += dy[dir];
		if (v[rx][ry] == 'O')
		{
			goalred = true;
			break;
		}
		if (v[rx][ry] == '#')
		{
			rx -= dx[dir];
			ry -= dy[dir];
			break;
		}
	}
}

void roll(int& rx, int& ry, int& bx, int& by, int dir, bool& goalred, bool& goalblue, vector<vector<char>>& v)
{
	int crx = rx;
	int cry = ry;
	int cbx = bx;
	int cby = by;

	if (dir == 0)
	{
		rollred(rx, ry, dir, goalred, v);
		rollblue(bx, by, dir, goalblue, v);
		if (rx == bx && ry == by)
		{
			if (crx > cbx) bx -= 1;
			else rx -= 1;
		}
	}
	if (dir == 1)
	{
		rollred(rx, ry, dir, goalred, v);
		rollblue(bx, by, dir, goalblue, v);
		if (rx == bx && ry == by)
		{
			if (crx > cbx) rx += 1;
			else bx += 1;
		}
	}
	if (dir == 2)
	{
		rollred(rx, ry, dir, goalred, v);
		rollblue(bx, by, dir, goalblue, v);
		if (rx == bx && ry == by)
		{
			if (cry > cby) by -= 1;
			else ry -= 1;
		}
	}
	if (dir == 3)
	{
		rollred(rx, ry, dir, goalred, v);
		rollblue(bx, by, dir, goalblue, v);
		if (rx == bx && ry == by)
		{
			if (cry > cby) ry += 1;
			else by += 1;
		}
	}
}

int bfs(int rx, int ry, int bx, int by, vector<vector<char>>& v)
{
	queue<pos> q;
	q.push({ rx,ry,bx,by,0});
	visited[rx][ry][bx][by] = true;

	while (!q.empty())
	{
		int crx = q.front().rx;
		int cry = q.front().ry;
		int cbx = q.front().bx;
		int cby = q.front().by;
		int cnt = q.front().cnt;
		if (cnt > 10) return -1;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nrx = crx;
			int nry = cry;
			int nbx = cbx;
			int nby = cby;
			
			bool goalblue = false;
			bool goalred = false;

			roll(nrx, nry, nbx, nby, i, goalred, goalblue, v);
			if (visited[nrx][nry][nbx][nby]) continue;
			if (goalred)
			{
				if (goalblue) continue;
				return cnt + 1 <= 10 ? cnt + 1 : -1;
			}
			if (goalblue) continue;

			visited[nrx][nry][nbx][nby] = true;
			q.push({ nrx, nry, nbx, nby, cnt + 1 });
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, m, rx, ry, bx, by;
	cin >> n >> m;

	vector<vector<char>> v(n, vector<char>(m, ' '));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == 'R')
			{
				rx = i;
				ry = j;
			}
			if (v[i][j] == 'B')
			{
				bx = i;
				by = j;
			}
		}
	}

	cout << bfs(rx, ry, bx, by, v);
}