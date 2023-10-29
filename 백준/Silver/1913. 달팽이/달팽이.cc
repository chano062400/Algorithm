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

int arr[1001][1001];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, fn;
	cin >> n >> fn;

	int dir = 0 , x = 1, y =1, fx = 0, fy = 0;
	for (int num = n * n; num >= 1; num--)
	{
		arr[x][y] = num;
		if (num == fn)
		{
			fx = x;
			fy = y;
		}

		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx > n || ny > n || nx < 1 || ny < 1 || arr[nx][ny] != 0)
		{
			dir = (dir + 1) % 4;
		}

		x += dx[dir];
		y += dy[dir];

	}
	
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}

	cout << fx << " " << fy;
}