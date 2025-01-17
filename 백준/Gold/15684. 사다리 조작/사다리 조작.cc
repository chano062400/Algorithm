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

const int MAX = 987654321;
int n, m, h, res = MAX;
bool ladder[31][11];

bool same()
{
	for (int i = 1; i <= n; i++)
	{
		int col = i;
		for (int j = 1; j <= h; j++)
		{
			// 오른쪽으로 이동
			if (ladder[j][col]) col++;
			// 왼쪽으로 이동.
			else if (ladder[j][col - 1]) col--;
		}
		if (col != i) return false;
	}
	return true;
}

void back(int index, int cnt)
{
	if (cnt > 3) return;
	if (same())
	{
		res = min(res, cnt);
		return;
	}

	for (int i = index; i <= h; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// 연속 가로선 방지
			if (ladder[i][j] || ladder[i][j - 1] || ladder[i][j + 1]) continue;
			ladder[i][j] = true;
			back(i, cnt + 1);
			ladder[i][j] = false;
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> h;
	
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		ladder[a][b] = true;
	}
	
	back(1, 0);

	if (res == MAX)
	{
		cout << -1;
	}
	else
	{
		cout << res;
	}
}


