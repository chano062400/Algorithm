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

// 18 19 20

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.second == p2.second) return p1.first < p2.first;
	return p1.second < p2.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	// 자르는 횟수, 10으로 나눈 나머지
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back({ num / 10, num % 10 });
	}

	sort(v.begin(), v.end(), cmp);

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i].second)
		{
			if (m - v[i].first >= 0)
			{
				res += v[i].first;
				m -= v[i].first;
			}
			else
			{
				res += m;
				break;
			}
		}
		else
		{
			if (m - (v[i].first - 1) >= 0)
			{
				res += v[i].first;
				m -= v[i].first - 1;
			}
			else
			{
				res += m;
				break;
			}
		}
	}
	cout << res;
}

