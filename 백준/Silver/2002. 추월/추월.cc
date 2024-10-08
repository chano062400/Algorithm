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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, res = 0;
	cin >> n;
	map<string, int> order;
	vector<int> v;
	vector<bool> check(n + 1, 1);
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		order.insert({ str,i });
	}

	int idx = 1;
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		if (idx != order[str])
		{
			res++;
			check[order[str]] = false;
		}
		else
		{
			check[idx] = false;
			for (int j = 1; j <= n; j++)
			{
				if (check[j])
				{
					idx = j;
					break;
				}
			}
		}
	}

	cout << res;

}

