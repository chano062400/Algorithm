#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "memory.h"
#include <set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
#include <limits.h>
#include <list>
using namespace std;

int GCD(int a, int b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int gcd, lcm;
	cin >> gcd >> lcm;

	int divide = lcm / gcd, a, b;
	for (int i = 1; i <= sqrt(divide); i++)
	{
		int j = divide / i;
		if (divide % i == 0)
		{
			if (GCD(i, j) == 1)
			{
				a = i;
				b = j;
			}
		}
	}

	cout << a * gcd << " " << b * gcd;
	
}


