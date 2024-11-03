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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	vector<int> v(n);

	int mx = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		mx = max(mx, v[i]);
	}

	vector<int> num(mx+1, 0);
	int l = 0, r = 0;
	num[v[0]] = 1;

	int res = 1;
	while (r < n - 1)
	{
		if (num[v[r + 1]] + 1 <= k)
		{
			num[v[r + 1]]++;
			r++;
			res = max(res, r - l + 1);
		}
		else if(num[v[r+1]] + 1 > k || l == r)
		{
			num[v[l]]--;
			l++;
		}
	}
	cout << res;
}