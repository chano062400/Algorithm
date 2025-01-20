#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "memory.h"
#include <set>
#include <unordered_set>
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

	int n, res = 0;
	cin >> n;

	priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
	vector<bool> check(1001, 0);
	for (int i = 1; i <= n; i++)
	{
		int day, score;
		cin >> day >> score;
		pq.push({ score, day });
	}

	while (!pq.empty())
	{
		int score = pq.top().first;
		int day = pq.top().second;
		pq.pop();

		for (int i = day; i >= 1; i--)
		{
			if (!check[i])
			{
				check[i] = true;
				res += score;
				break;
			}
		}
	}
	cout << res;
}
