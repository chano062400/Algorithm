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

	map<string, int> check;
	string s, e, se, time, id;
	int res = 0;
	cin >> s >> e >> se;

	while (!cin.eof())
	{
		cin >> time >> id;
		if (time <= s)
		{
			check[id] = 1;
		}
		else if (time >= e && time <= se && check[id] == 1)
		{
			check[id] = 2;
			res++;
		}
	}
	cout << res;
}

