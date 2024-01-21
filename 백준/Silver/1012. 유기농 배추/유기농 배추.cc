#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int total, a, b, c,cnt;
int arr[50][50];
bool visited[50][50];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };

void reset()
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			arr[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

void dfs(int y, int x)
{	
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= a || nx >= b) continue;
		if (!visited[ny][nx] && arr[ny][nx])
		{
			visited[ny][nx] = 1;
			dfs(ny, nx);
		}
	}
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> total;
	for (int t = 0; t < total; t++)
	{
		cnt = 0;
		cin >> a >> b >> c;
		for (int i = 0; i < c; i++)
		{
			int x, y;
			cin >> x >> y;
			arr[x][y] = 1;
		}

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				if (!visited[i][j] && arr[i][j] == 1)
				{

					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
		reset();
	}
}
	