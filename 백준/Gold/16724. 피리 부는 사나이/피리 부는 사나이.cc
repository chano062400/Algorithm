#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "memory.h"
#include <set>
using namespace std;

char arr[1001][1001];
int visited[1001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m, res = 0;

void dfs(int x, int y, int cnt)
{
	if (visited[x][y])
	{
		if (visited[x][y] == cnt) res++;
		return;
	}

	int dir;
	if (arr[x][y] == 'D') dir = 0;
	else if (arr[x][y] == 'U') dir = 1;
	else if (arr[x][y] == 'R') dir = 2;	
	else dir = 3;

	visited[x][y] = cnt;
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	dfs(nx, ny, cnt);
	
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
		}
	}

	int cnt = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if(!visited[i][j])
			{
				dfs(i, j, cnt);
				cnt++;
			}
		}
	}

	cout << res;
}