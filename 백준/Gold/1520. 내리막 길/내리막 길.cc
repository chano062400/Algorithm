#include<iostream>
#include<algorithm>
#include<queue>
#include "memory.h"

using namespace std;

int a, b, cnt =0;
int arr[500][500];
int dp[500][500];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

int dfs(int y, int x)
{
	if (y == a - 1 && x == b - 1)
	{
		return 1;
	}
	if (dp[y][x] != -1) return dp[y][x];

	dp[y][x] = 0;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

	if(ny>=0 && nx>=0 && ny<a && nx<b)
		if(arr[ny][nx] < arr[y][x])
			dp[y][x] += dfs(ny,nx);
	}

	return dp[y][x];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}


	cout << dfs(0, 0);
		

}
	