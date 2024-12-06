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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, res = 0;
	cin >> n >> m;
	string s;
	cin >> s;

	int pattern = 2 * n + 1, len;
	len = s[0] == 'I' ? 1 : 0;

	for (int i = 1; i < m; i++)
	{
		if ((s[i - 1] == 'I' && s[i] == 'O') ||
			(s[i - 1] == 'O' && s[i] == 'I')) len++;
		else
		{
			if (len >= pattern)
			{
				res += (len - pattern) / 2 + 1;
			}

			len = s[i] == 'I' ? 1 : 0;
		}
	}

	if (len >= pattern)
	{
		res += (len - pattern) / 2 + 1;
	}

	cout << res;
}

