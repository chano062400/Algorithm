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

int n, q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> q;

	vector<int> v(n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < n; i++)
	{
		sum += v[i] * v[(i + 1) % n] * v[(i + 2) % n] * v[(i + 3) % n];
	}

	for (int i = 0; i < q; i++)
	{
		int idx; 
		cin >> idx;
		idx -= 1;
		v[idx] *= -1;

		int tempsum = 0;

		for (int j = idx - 3; j <= idx; j++)
		{
			int tempj = j;
			if (j < 0) tempj = n + j;
			tempsum += v[tempj] * v[(tempj + 1) % n] * v[(tempj + 2) % n] * v[(tempj + 3) % n];
		}

		sum += 2 * tempsum;

		cout << sum << '\n';
	}
}

