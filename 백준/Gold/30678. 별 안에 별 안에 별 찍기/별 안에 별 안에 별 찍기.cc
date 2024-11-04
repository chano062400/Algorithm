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

void dq(int x, int y, int len, vector<vector<char>>& arr)
{
	if (len == 0)
	{
		arr[x][y] = '*';
		return;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i < 2)
			{
				if (j == 2)
				{
					dq(x + i * len, y + j * len, len / 5, arr);
				}
			}
			else if (i == 2)
			{
				dq(x + i * len, y + j * len, len / 5, arr);
			}
			else if (i == 3 && (j != 0 && j != 4))
			{
				dq(x + i * len, y + j * len, len / 5, arr);
			}
			else if (i == 4 && (j != 0 && j != 2 && j != 4))
			{
				dq(x + i * len, y + j * len, len / 5, arr);
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	cin >> n;
	vector<vector<char>> arr(pow(5,n), vector<char>(pow(5,n), ' '));
	dq(0, 0, pow(5,n - 1), arr);

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[0].size(); j++)
		{
			cout << arr[i][j];
		}
		cout << '\n';
	}
}