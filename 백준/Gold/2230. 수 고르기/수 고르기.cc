#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int l = 0, r = 0, res = 1e9 * 2;
	while (r < n && l <= r)
	{
		int dif = abs(v[l] - v[r]);
		if (dif < m)
		{
			r++;
		}
		else
		{
			l++;
			res = min(res, dif);
		}
	}

	cout << res;
}