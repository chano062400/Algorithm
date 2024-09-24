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
	
	int n;
	cin >> n;

	vector<pair<int, int>> v(n+1);
	long long sum = 0;
	for(int i=1; i<=n; i++)
	{ 
		cin >> v[i].first >> v[i].second;
		sum += v[i].second;
	}

	sort(v.begin() + 1, v.end());

	long long cursum = 0;
	for (int i = 1; i <= n; i++)
	{
		cursum += v[i].second;
		if (cursum >= (sum + 1) / 2)
		{
			cout << v[i].first;
			return 0;
		}
	}


}

