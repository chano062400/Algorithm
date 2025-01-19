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

int n, m, weights[31];
unordered_set<int> weight;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (i > 0)
		{
			vector<int> temp;
			for (auto it = weight.begin(); it != weight.end(); it++)
			{
				temp.push_back(*it);
			}

			for (int j = 0; j < temp.size(); j++)
			{
				int w1 = abs(weights[i] + temp[j]);
				int w2 = abs(weights[i] - temp[j]);
				weight.insert(w1);
				weight.insert(w2);
			}
		}
		weight.insert(weights[i]);
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int bead;
		cin >> bead;
		if (weight.find(bead) != weight.end())
		{
			cout << "Y ";
		}
		else
		{
			cout << "N ";
		}
	}

}


