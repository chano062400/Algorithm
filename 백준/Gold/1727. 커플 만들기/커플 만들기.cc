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

int a, b, dp[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> a >> b;
	
	vector<int> m, wm;
	for (int i = 0; i < a; i++)
	{
		int num;
		cin >> num;
		m.push_back(num);
	}
	for (int i = 0; i < b; i++)
	{
		int num;
		cin >> num;
		wm.push_back(num);
	}

	sort(m.begin(), m.end());
	sort(wm.begin(), wm.end());

	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			if (i == j)
			{
				dp[i][j] = dp[i-1][j-1] + abs(m[i - 1] - wm[j - 1]);
			}
			else if (i > j)
			{
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + abs(m[i - 1] - wm[j - 1]));
			}
			else if (j > i)
			{
				dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(m[i - 1] - wm[j - 1]));
			}
		}
	}

	cout << dp[a][b];
}

