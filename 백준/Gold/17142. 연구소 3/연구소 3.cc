#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "memory.h"
#include <set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
#include <limits.h>
#include <list>
using namespace std;

#define MAX 99999

int n, m, zero = 0, res = MAX;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void bfs(vector<vector<char>>& temp, const vector<pair<int, int>>& pos)
{
	vector<vector<int>> visited(n + 1, vector<int>(n + 1, -1));
	
	queue<pair<int, int>> q;
	for (auto& pair : pos)
	{
		q.push({ pair.first, pair.second });
		visited[pair.first][pair.second] = 0;
	}

	int cnt = zero, mx = 0;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		if (cnt == 0)
		{
			res = min(res, mx);
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
			if (visited[nx][ny] != -1 || temp[nx][ny] == '-') continue;
		
			visited[nx][ny] = visited[cx][cy] + 1;
			if (temp[nx][ny] == '0')
			{
				cnt--;
				mx = max(mx, visited[nx][ny]);
			}	
			q.push({ nx, ny });
		}
	}
}

void back(int idx, const vector<vector<char>>& arr,const vector<pair<int, int>>& v, vector<bool> check, vector<pair<int, int>> pos)
{
	if (pos.size() == m)
	{
		vector<vector<char>> temp = arr;
		bfs(temp, pos);
		return;
	}

	for (int i = idx; i < v.size(); i++)
	{
		if (!check[i])
		{
			check[i] = true;
			pos.push_back(v[i]);
			back(i + 1, arr, v, check, pos);
			pos.pop_back();
			check[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	vector<vector<char>> arr(n + 1, vector<char>(n + 1, 0));
	vector<pair<int, int>> v, pos;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == '1')
			{
				arr[i][j] = '-';
			}
			if (arr[i][j] == '2')
			{
				v.push_back({ i,j });
			}
			if (arr[i][j] == '0')
			{
				zero++;
			}
		}
	}
	vector<bool> check(v.size(), 0);

	back(0, arr, v, check, pos);

	if (res == MAX) cout << -1;
	else cout << res;
}


