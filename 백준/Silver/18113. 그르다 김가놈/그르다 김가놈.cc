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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, k, m;
	cin >> n >> k >> m;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int start = 1, end = 1e9, res = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int cnt = 0;

		for (const auto& len : v)
		{
			if (len >= 2 * k)
			{
				cnt += (len - (2 * k)) / mid;
			}
			else if (len >= k && len < 2 * k)
			{
				cnt += (len - k) / mid;
			}
		}

		if (cnt < m)
		{	
			end = mid - 1;
		}
		else
		{
			res = max(res, mid);
			start = mid + 1;
		}
	}

	res == 0 ? cout << -1 : cout << res;
}

