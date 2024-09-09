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
		long long a, b;
		cin >> a >> b;

		long long i;
		while (a != 1)
		{
			i = b % a == 0 ? b / a : b / a + 1;
			a = a * i - b;
			b = b * i;

			long long GCD = gcd(a, b);
			a /= GCD;
			b /= GCD;
		}

		cout << b << '\n';
	}
}

