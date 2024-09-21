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

long long gcd(long long a, long long b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		
		int GCD = gcd(m, n);
		long long LCM = m * n / GCD;

		long long cnt = x;
		while (1)
		{
			if (cnt - y >= 0 && (cnt - y) % n == 0 && cnt <= LCM)
			{
				cout << cnt << '\n';
				break;
			}
			else if (cnt > LCM)
			{
				cout << -1 << '\n';
				break;
			}
			cnt += m;
		}
	}
}

