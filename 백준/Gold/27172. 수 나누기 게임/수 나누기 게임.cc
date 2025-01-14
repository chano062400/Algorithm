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

#define MAX 1000001
bool check[1000001];
int res[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	
	vector<int> v(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		check[v[i]] = true;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = v[i] * 2; j < MAX; j += v[i])
		{
			// v[i]의 배수가 존재한다면
			if (check[j])
			{
				res[v[i]]++;
				res[j]--;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << res[v[i]] << " ";
	}

}


