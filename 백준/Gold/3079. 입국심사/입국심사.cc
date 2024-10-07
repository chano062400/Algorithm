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

	int n, m;
	cin >> n >> m;

	vector<long long> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());

	// 최대 시간 - 가장 시간이 적게 걸리는 심사대에서 m명이 심사받을 때
	long long start = 1, end = v[0] * m, res = end;
	while (start <= end)
	{
		long long mid = (start + end) / 2;

		long long cnt = 0;
		for (int t : v)
		{
			cnt += mid / t;
		}

		if (cnt >= m)
		{
			end = mid - 1;
			res = min(res, mid);
		}
		else
		{
			start = mid + 1;
		}
	}

	cout << res;
}

