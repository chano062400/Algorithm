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

int n, m, k, arr[51][51], copyarr1[51][51], copyarr2[51][51];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

struct Info
{
	int r, c, s;
};

void Copy(int arr1[51][51], int arr2[51][51])
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			arr1[i][j] = arr2[i][j];
		}
	}
}

void rotate(int r, int c, int s)
{
	int dir = -1, x = r - s, y = c - s;
	while (1)
	{
		if ((x == r - s || x == r + s) && (y == c + s || y == c - s)) dir += 1;
		if (dir == 4)
		{
			x += 1;
			y += 1;
			s -= 1;
			dir = 0;
		}
		if (x == r && y == c) break;

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		
		copyarr1[nx][ny] = copyarr2[x][y];
		x = nx;
		y = ny;
	}
	Copy(copyarr2, copyarr1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
			copyarr1[i][j] = arr[i][j];
			copyarr2[i][j] = arr[i][j];
		}
	}

	vector<Info> v;
	vector<int> idx(k);
	for (int i = 0; i < k; i++)
	{
		idx[i] = i;
	}

	while (k--)
	{
		int r, c, s;
		cin >> r >> c >> s;
		v.push_back({ r,c,s });
	}

	int res = 987654321;

	do
	{
		for (int i = 0; i < v.size(); i++)
		{
			rotate(v[idx[i]].r, v[idx[i]].c, v[idx[i]].s);
		}

		for (int i = 1; i <= n; i++)
		{
			int csum = 0;
			for (int j = 1; j <= m; j++)
			{
				csum += copyarr1[i][j];
			}
			res = min(res, csum);
		}
		Copy(copyarr1, arr);
		Copy(copyarr2, arr);
	} while (next_permutation(idx.begin(), idx.end()));

	
	cout << res;
}

