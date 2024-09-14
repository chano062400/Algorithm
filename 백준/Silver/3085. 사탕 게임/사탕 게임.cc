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

int n, res;
char arr[51][51], copyarr[51][51];
bool visited[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1};

void swapcheck(int x, int y, int nx, int ny)
{
	int cnt = 0;
	char ch;

	if (x == nx && y == ny)
	{
		ch = arr[x][1];
		for (int i = 1; i <= n; i++)
		{
			if (ch == arr[x][i]) cnt++;
			else 
			{
				ch = arr[x][i];
				cnt = 1;
			}
			res = max(res, cnt);
		}

		cnt = 0;

		ch = arr[1][y];
		for (int i = 1; i <= n; i++)
		{
			if (ch == arr[i][y]) cnt++;
			else
			{
				ch = arr[i][y];
				cnt = 1;
			}
			res = max(res, cnt);
		}
	}
	else
	{
		swap(copyarr[x][y], copyarr[nx][ny]);

		if (x != nx)
		{
			ch = copyarr[x][1];

			for (int i = 1; i <= n; i++)
			{
				if (ch == copyarr[x][i]) cnt++;
				else
				{
					ch = copyarr[x][i];
					cnt = 1;
				}
				res = max(res, cnt);
			}

			cnt = 0;

			ch = copyarr[nx][1];
			for (int i = 1; i <= n; i++)
			{
				if (ch == copyarr[nx][i]) cnt++;
				else
				{
					ch = copyarr[nx][i];
					cnt = 1;
				}
				res = max(res, cnt);
			}

			cnt = 0;

			ch = copyarr[1][y];
			for (int i = 1; i <= n; i++)
			{
				if (ch == copyarr[i][y]) cnt++;
				else
				{
					ch = copyarr[i][y];
					cnt = 1;
				}
				res = max(res, cnt);
			}
		}
		else if (y != ny)
		{
			ch = copyarr[1][y];
			for (int i = 1; i <= n; i++)
			{
				if (ch == copyarr[i][y]) cnt++;
				else
				{
					ch = copyarr[i][y];
					cnt = 1;
				}

				res = max(res, cnt);
			}

			cnt = 0;

			ch = copyarr[1][ny];
			for (int i = 1; i <= n; i++)
			{
				if (ch == copyarr[i][ny]) cnt++;
				else
				{
					ch = copyarr[i][ny];
					cnt = 1;
				}

				res = max(res, cnt);
			}

			cnt = 0;

			ch = copyarr[x][1];
			for (int i = 1; i <= n; i++)
			{
				if (ch == copyarr[x][i]) cnt++;
				else
				{
					ch = copyarr[x][i];
					cnt = 1;
				}

				res = max(res, cnt);
			}
		}
	}

	swap(copyarr[x][y], copyarr[nx][ny]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= n; j++)
		{
			arr[i][j] = str[j - 1];
			copyarr[i][j] = arr[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

				swapcheck(i, j, nx, ny);
				
			}
		}
	}
	cout << res;
}

