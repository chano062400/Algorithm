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

struct Info
{
	int x, y, dist;
};

int n, m, sx, sy;
vector<vector<int>> arr(3001, vector<int>(3001));
bool visited[3001][3001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
 
bool bfs(int x, int y)
{
	queue<Info> q;
	q.push({ x,y,0 });
	visited[x][y] = true;
	
	while (!q.empty())
	{
		int cx = q.front().x;
		int cy = q.front().y;
		int cd = q.front().dist;
		q.pop();

		if (arr[cx][cy] > 2)
		{
			cout << "TAK\n" << cd;
			return true;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (visited[nx][ny] || arr[nx][ny] == 1) continue;
		
			q.push({ nx,ny,cd + 1 });
			visited[nx][ny] = true;

		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++)
		{
			arr[i][j] = str[j - 1] - '0';

			if (arr[i][j] == 2)
			{
				sx = i;
				sy = j;
			}
		}
	}

	if (!bfs(sx, sy)) cout << "NIE" << '\n';
}

