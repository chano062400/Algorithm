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
	vector<int> v(1001,0);
	
	int maxheight = 0, maxheightidx = 0, minidx = 1001, maxidx = 0;
	for (int i = 0; i < n; i++)
	{
		int l, h;
		cin >> l >> h;
		v[l] = h;
		
		minidx = min(minidx, l);
		maxidx = max(maxidx, l);

		if (h > maxheight)
		{
			maxheight = h;
			maxheightidx = l;
		}
	}

	int prevheight = v[minidx];
	for (int i = minidx; i < maxheightidx; i++)
	{
		if (v[i] != 0)
		{
			v[i] = max(prevheight, v[i]);
			prevheight = v[i];
		}
		else v[i] = prevheight;
	}

	prevheight = v[maxidx];
	for (int i = maxidx; i > maxheightidx; i--)
	{
		if (v[i] != 0)
		{
			v[i] = max(prevheight, v[i]);
			prevheight = v[i];
		}
		else v[i] = prevheight;
	}

	int sum = 0;
	for (int i = minidx; i <= maxidx; i++)
	{
		sum += v[i];
	}

	cout << sum;
}

