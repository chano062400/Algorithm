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
using namespace std;

struct info
{
	int x, y, dist;
};

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2)
{
	if (p1.first == p2.first)  return p1.second < p2.second;
	return p1.first < p2.first;
}

bool cmp2(const info& info1, const info& info2)
{
	if (info1.dist == info2.dist) return info1.y < info2.y;
	return info1.dist < info2.dist;
}

int n, m, d;
int arr[15][15];
vector<int> archerloc;

int bfs()
{
	vector<vector<int>> temp(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			temp[i][j] = arr[i][j];
		}
	}
	
	// 성에서 가까운 적부터 넣음.
	queue<pair<int, int>> q;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			if (temp[i][j] == 1)
			{
				q.push({ i,j });
			}
		}
	}

	vector<vector<info>> attack(m);
	vector<pair<int, int>> move;
	int cnt = 0;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < m; i++) attack[i].clear();
		move.clear();

		for (int i = 0; i < size; i++)
		{
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();	
		
			for (int j = 0; j < m; j++)
			{
				if (archerloc[j] == 0) continue;

				int dist = abs(n - cx) + abs(j - cy);
				if (dist <= d)
				{
					attack[j].push_back({ cx, cy, dist });
				}
			}
			move.push_back({ cx, cy });
		}

		// 궁수마다 가장 가까운 적 공격
		for (int i = 0; i < m; i++)
		{
			if (attack[i].empty()) continue;

			sort(attack[i].begin(), attack[i].end(), cmp2);
			
			// 다른 궁수에게 공격받은 적
			if (temp[attack[i].front().x][attack[i].front().y] == 0) continue;

			temp[attack[i].front().x][attack[i].front().y] = 0;
			cnt++;
		}

		for (auto pair : move)
		{
			// 궁수에게 공격받아 죽은 적
			if (temp[pair.first][pair.second] == 0) continue;
			temp[pair.first][pair.second] = 0;
			
			// 성 안에 들어가는 적
			if (pair.first + 1 == n) continue;
			temp[pair.first + 1][pair.second] = 1;

			q.push({ pair.first + 1, pair.second });
		}
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);	
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	vector<int> v(m, 0);
	v[m - 3] = v[m - 2] = v[m - 1] = 1;
	archerloc = v;

	int res = 0;
	do
	{
		res = max(res, bfs());
	}
	while (next_permutation(archerloc.begin(), archerloc.end()));

	cout << res;
}

