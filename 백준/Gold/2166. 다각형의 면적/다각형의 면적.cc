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
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
using namespace std;

long long CrossProduct(long long x1, long long x2, long long x3, long long y1, long long y2, long long y3)
{
	return (x1 * y2) + (x2 * y3) + (x3 * y1) - (y1 * x2) - (y2 * x3) - (y3 * x1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	double sum = 0.f;
	for (int i = 1; i < n - 1; i++)
	{
		sum += CrossProduct(v[0].first, v[i].first, v[i + 1].first, v[0].second, v[i].second, v[i + 1].second) / (double) 2;
	}
	cout.precision(1);
	cout << fixed;
	cout << abs(sum);

}