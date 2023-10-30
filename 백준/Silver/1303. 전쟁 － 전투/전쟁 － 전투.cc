#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <iomanip>
#include "algorithm"
#include <cmath>
#include <stack>
#include <regex>
#include <map>
using namespace std;

char arr[101][101];
bool visited[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;

int bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = 1;

	int ccnt = 1;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 1 && ny >= 1 && nx <= m && ny <= n && !visited[nx][ny])
			{
				if (arr[cx][cy] == arr[nx][ny])
				{
					visited[nx][ny] = 1;
					q.push({ nx,ny });
					ccnt++;
				}
			}
		}
	}


	return ccnt * ccnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= n; j++)
		{
			arr[i][j] = str[j-1];
		}
	}

	memset(visited, 0, sizeof(visited));

	int W = 0, B = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!visited[i][j])
			{	
				if (arr[i][j] == 'W')
				{
					W += bfs(i, j);
				}
				else B += bfs(i, j);
			}
		}
	}

	cout << W << " " << B;
}