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
	
long long sum[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	
	for (int i = 1; i <= 1000000; i++)
	{
		for (int j = i; j <= 1000000; j+=i)
		{
			// i의 배수에 i를 모두 더해줌.
			sum[j] += i;
		}
		sum[i] += sum[i - 1];
	}

	while (n--)
	{
		int num;
		cin >> num;

		cout << sum[num] << '\n';
	}
}


