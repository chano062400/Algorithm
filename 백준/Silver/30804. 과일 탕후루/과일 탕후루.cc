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

int fruit[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, cnt = 0, res = 0;
	cin >> n;

	queue<int> q;
	while (n--)
	{
		int num;
		cin >> num;

		q.push(num);

		if (fruit[num]++ == 0) cnt++;

		while (cnt > 2)
		{
			int cur = q.front();
			q.pop();

			if (--fruit[cur] == 0) --cnt;
		}

		res = max(res, (int)q.size());
	}

	cout << res;
}

