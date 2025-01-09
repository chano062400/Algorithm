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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	long long res = 0;
	cin >> n;

	stack<int> st;
	for (int i = 1; i <= n; i++)
	{
		int height;
		cin >> height;

		if (st.empty())
		{
			st.push(height);
		}
		else
		{
			if (height < st.top()) res += st.size();
			else
			{
				while (!st.empty() && st.top() <= height)
				{
					st.pop();
				}
				res += st.size();
			}
			st.push(height);
		}
	}

	cout << res;
}


