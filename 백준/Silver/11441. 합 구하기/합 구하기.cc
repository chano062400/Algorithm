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
	cin >> n;
	vector<int> v(n+1,0), sum(n+1);
	
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		sum[i] += sum[i - 1] + v[i];
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;

		cout << sum[e] - sum[s-1] << '\n';
	}

}

