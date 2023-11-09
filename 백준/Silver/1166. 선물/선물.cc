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
using namespace std;

long long n, l, w, h;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> l >> w >> h;

	long double mx = max(max(l, w), h);
	long double start = 0, end = mx;


	for(int i=0; i< 10000; i++)
	{
		long double mid = (start + end) / 2;

		if ((long long)(l / mid) * (long long)(w / mid) * (long long)(h / mid) >= n) start = mid;
		else
		{
			end = mid;
		}
	}

	cout << fixed << setprecision(9);

	cout << end;
}