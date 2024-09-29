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

	vector<int> v(n), res;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	res.push_back(v[0]);
	for (int i = 1; i < n; i++)
	{
		int idx = lower_bound(res.begin(), res.end(), v[i]) - res.begin();
		if (idx >= res.size()) res.push_back(v[i]);
		else res[idx] = v[i];
	}

	cout << n - res.size();
}

