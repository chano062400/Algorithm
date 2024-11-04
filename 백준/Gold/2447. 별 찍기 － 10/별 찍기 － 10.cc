#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "memory.h"
#include <set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
using namespace std;

char arr[7000][7000];

void star(int x, int y, int len, bool empty)
{
	if (len == 0)
	{
		if (empty) arr[x][y] = ' ';
		else arr[x][y] = '*';
		return;
	}
	star(x, y, len / 3, empty);
	star(x, y + len, len / 3, empty);
	star(x, y + len * 2, len / 3, empty);
	star(x + len, y, len / 3, empty);
	star(x + len, y + len, len / 3, true);
	star(x + len, y + len * 2, len / 3, empty);
	star(x + len * 2, y, len / 3, empty);
	star(x + len * 2, y + len, len / 3, empty);
	star(x + len * 2, y + len * 2, len / 3, empty);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	cin >> n;
	star(0, 0, n / 3, false);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j];
		}
		cout << '\n';
	}
}