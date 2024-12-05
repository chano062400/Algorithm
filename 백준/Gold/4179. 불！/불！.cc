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
using namespace std;

int n, m, sx , sy;
char arr[1001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool visited[1001][1001];
vector<pair<int, int>> fire, jh;

void firespread()
{
	int size = fire.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int nx = fire[i].first + dx[j];
			int ny = fire[i].second + dy[j];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (arr[nx][ny] == '#' || arr[nx][ny] == 'F') continue;
			arr[nx][ny] = 'F';
			fire.push_back({ nx,ny });
		}
	}
	fire.erase(fire.begin(), fire.begin() + size);
}

void print()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void bfs()
{
	queue<pair<pair<int, int>,int>> q;
	q.push({ { sx,sy },0 });
	visited[sx][sy] = true;

	while (!q.empty())
	{
		int size = q.size();
		for (int sz = 0; sz < size; sz++)
		{
			int cx = q.front().first.first;
			int cy = q.front().first.second;
			int curtime = q.front().second;
			q.pop();
			if (arr[cx][cy] == 'F') continue;
			arr[cx][cy] = '.';

			for (int i = 0; i < 4; i++)
			{
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 0 || nx > n + 1 || ny < 0 || ny > m + 1) continue;
				if (arr[nx][ny] == '#' || arr[nx][ny] == 'F') continue;
				if (visited[nx][ny]) continue;
				visited[nx][ny] = true;
				if (nx == 0 || nx == n + 1 || ny == 0 || ny == m + 1)
				{
					cout << curtime + 1;
					return;
				}
				arr[nx][ny] = 'J';
				q.push({ { nx,ny }, curtime + 1 });
			}
		}
		
		firespread();
	}
	cout << "IMPOSSIBLE";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'J')
			{
				sx = i;
				sy = j;
			}
			if (arr[i][j] == 'F') fire.push_back({ i,j });
		}
	}
		
	bfs();
}

