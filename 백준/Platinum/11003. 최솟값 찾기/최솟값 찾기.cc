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

int main()
{
	ios::sync_with_stdio(false);	
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, l;
	cin >> n >> l;
	
	deque<pair<int, int>> dq;
	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		while (!dq.empty() && dq.front().second <= i - l)
		{
			dq.pop_front();
		}

		while (!dq.empty() && dq.back().first > num)
		{
			dq.pop_back();
		}

		dq.push_back({ num,i });

		cout << dq.front().first << " ";
	}

}

