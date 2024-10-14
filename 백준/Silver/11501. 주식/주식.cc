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

	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		long long res = 0;
		int MAX = -1;
		for (int i = n - 1; i >= 0; i--)
		{
			MAX = max(MAX, v[i]);
			res += MAX - v[i];
		}

		cout << res << '\n';
	}

}

