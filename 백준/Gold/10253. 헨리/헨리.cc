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

int gcd(int a, int b)
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

		long long x, y, i = 2;

		while (1)
		{
			long long gcdab = gcd(a, b);
			if (gcdab != 1)
			{
				a /= gcdab;
				b /= gcdab;
			}

			if (a == 1)
			{
				cout << b << '\n';
				break;
			}

			long long GCD = gcd(b, i);
			long long LCM = i * b / GCD;

			long long tempa = a * (LCM / b), tempb = LCM;
			y = LCM;
			x = (LCM / i);
			if (tempa >= x)
			{
				b = tempb;
				a = tempa;
				a -= x;
				if (a) i = b / a;
				else i++;
			}
			else i++;
			
		}

	}
}

