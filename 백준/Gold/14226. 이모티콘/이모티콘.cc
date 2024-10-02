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

bool check[10001][10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, time = 0;
	cin >> n;

	queue<pair<pair<int, int>,int>> q;
	q.push({ { 1,0 },0 });

	while (1)
	{
		int cs = q.front().first.first;
		int cc = q.front().first.second;
		int ct = q.front().second;
		q.pop();

		if (cs == n) 
		{
			time = ct; 
			break;
		}

		if (cs > 0 && !check[cs][cs])
		{
			q.push({ { cs,cs }, ct + 1 });
			check[cs][cs] = true;
		}
		if (cc > 0 && !check[cs + cc][cc])
		{
			q.push({ { cs + cc, cc }, ct + 1 });
			check[cs + cc][cc] = true;
		}
		if (cs - 1 >= 0 && !check[cs - 1][cc])
		{
			q.push({ { cs - 1,cc }, ct + 1 });
			check[cs - 1][cc] = true;
		}

	}

	cout << time;
}

