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
using namespace std;

#define MAX 3 * 1e9 + 1

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<long long> v(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin() + 1, v.end());

	int left, right, a , b, c;
	long long res = MAX;
	for (int i = 1; i <= n - 2; i++)
	{
		left = i + 1;
		right = n;
		
		long long sum;
		while (left < right)
		{
			sum = v[i] + v[left] + v[right];
			if (abs(sum) < abs(res))
			{
				a = i;
				b = left;
				c = right;
				res = abs(sum);
			}
			// 음수라면 0에 가깝게 만들기 위해 left를 증가.
			if (sum < 0)
			{
				++left;
			}
			// 양수라면 0에 가깝게 만들기 위해 right를 감소.
			else
			{
				if (sum == 0)
				{
					cout << v[i] << " " << v[left] << " " << v[right];
					return 0;
				}
				--right;
			}
		}
		
	}
	cout << v[a] << " " << v[b] << " " << v[c];
}


