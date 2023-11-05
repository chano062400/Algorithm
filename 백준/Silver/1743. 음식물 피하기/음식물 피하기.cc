#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stack>
#include <regex>
#include <map>
#include <cstdlib>
using namespace std;

int n, m, k, res=0 ;
int arr[101][101];
bool visited[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
 
void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = 1;
	int food = 1;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny] && arr[nx][ny] == 1)
			{
				visited[nx][ny] = 1;
				q.push({ nx,ny });
				food++;
			}
		}
	}

	res = max(res, food);
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> k;

	memset(arr, 0, sizeof(arr));
	memset(visited, 0, sizeof(visited));
	
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] == 1)
			{
				bfs(i, j);
				memset(visited, 0, sizeof(visited));
			}
		}
	}

	cout << res;
}