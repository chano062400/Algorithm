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

int n,res =0, friends;
vector<vector<char>> arr(50);
bool num[51][51];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			arr[i].push_back(str[j]);
		}
	}

	memset(num, 0, sizeof(num));

	for (int h = 0; h < n; h++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == 'Y')
				{
					if (i == j)continue;
					num[i][j] = 1;
				}
				else
				{
					if (arr[i][h] == 'Y' && arr[h][j] == 'Y' && !num[i][j])
					{
						if (i == j) continue;
						num[i][j] = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		friends = 0;
		for (int j = 0; j < n; j++)
		{
			if (num[i][j] == 1) friends++;
		}
		res = max(res, friends);
	}
	cout << res;
}