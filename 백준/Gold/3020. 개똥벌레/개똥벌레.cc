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
	
	int n, h;
	cin >> n >> h;
	
	vector<int> v(n/2), v2(n/2);
	for (int i = 0; i < n/2; i++)
	{
		cin >> v[i] >> v2[i];
	}

	sort(v.begin(), v.end());
	sort(v2.begin(), v2.end());

	int obstacles, res = 0, MIN = n;
	for (int i = 1; i <= h; i++)
	{
		int cnt = lower_bound(v.begin(), v.end(), i) - v.begin();
		cnt += upper_bound(v2.begin(), v2.end(), h - i) - v2.begin();
		
		obstacles = n - cnt;
		if (obstacles == MIN) res++;
		else if (obstacles < MIN)
		{
			res = 1;
			MIN = obstacles;
		}
	}

	cout << MIN << " " << res;
}

