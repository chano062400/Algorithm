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

int arr[501][501], n, m ,b;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
vector<pair<int, int>> sum;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first == p2.first) return p1.second > p2.second;
	return p1.first < p2.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> b;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	int res = 0;
	for (int targetheight = 0; targetheight <= 256; targetheight++)
	{
		int removeblock = 0, putblock = 0;
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < m; y++)
			{
				int curheight = arr[x][y], heightdif = abs(targetheight - curheight);

				if (targetheight > curheight) putblock += heightdif;
				else if (targetheight < curheight) removeblock += heightdif;
			}
		}

		int timesum;
		if (b + removeblock >= putblock)
		{
			timesum = removeblock * 2 + putblock;
		}
		else continue;

		sum.push_back({ timesum, targetheight });
	}

	sort(sum.begin(), sum.end(), cmp);

	cout << sum[0].first << " " << sum[0].second;
}

