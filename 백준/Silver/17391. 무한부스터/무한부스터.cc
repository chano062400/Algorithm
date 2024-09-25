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
#include <list>
#include <sstream>
#include <bitset>
#include <set>
#include <unordered_map>
#include <numeric>
#include <memory>
using namespace std;

int n, m, arr[301][301];
bool visited[301][301];
int dx[] = { 1,0 };
int dy[] = { 0,1 };

int bfs()
{
	queue<pair<pair<int, int>,int>> q;
	q.push({ {1,1},0 });
	visited[1][1] = true;

	while (!q.empty())
	{
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (cx == n && cy == m) return cnt;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < arr[cx][cy]; j++)
			{
				int nx = cx + dx[i] * (j + 1);
				int ny = cy + dy[i] * (j + 1);

				if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
				if (visited[nx][ny]) continue;

				q.push({ {nx,ny}, cnt+1 });
				visited[nx][ny] = 1;
			}
		}
	}
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
	
	cout << bfs();
}

