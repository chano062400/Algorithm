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

struct bottles
{
	int a, b, c;
};

int a, b, c;
bool check[201][201][201];
vector<int> v;
queue<bottles> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> a >> b >> c;

	q.push({ 0,0,c });

	while (!q.empty())
	{
		int ca = q.front().a;
		int cb = q.front().b;
		int cc = q.front().c;
		if(ca == 0) v.push_back(cc);
		q.pop();

		if (ca < a)
		{
			int need = a - ca;
			if (cb >= need)
			{
				if (!check[a][cb - need][cc])
				{
					q.push({ a, cb - need, cc });
					check[a][cb - need][cc] = true;
				}
			}
			else
			{
				if (!check[ca + cb][0][cc])
				{
					q.push({ ca + cb, 0, cc });
					check[ca + cb][0][cc] = true;
				}
			}

			if (cc >= need)
			{
				if (!check[a][cb][cc - need])
				{
					q.push({ a, cb, cc - need });
					check[a][cb][cc - need] = true;
				}
			}
			else
			{
				if (!check[ca + cc][cb][0])
				{
					q.push({ ca + cc, cb,0 });
					check[ca + cc][cb][0] = true;
				}
			}
		}

		if (cb < b)
		{
			int need = b - cb;
			if (ca >= need)
			{
				if (!check[ca - need][b][cc])
				{
					q.push({ ca - need, b, cc });
					check[ca - need][b][cc] = true;
				}
			}
			else
			{
				if (!check[0][ca + cb][cc])
				{
					q.push({ 0, ca + cb, cc });
					check[0][ca + cb][cc] = true;
				}
			}

			if (cc >= need)
			{
				if (!check[ca][b][cc - need])
				{
					q.push({ ca,b,cc - need });
					check[ca][b][cc - need] = true;
				}
			}
			else
			{
				if (!check[ca][cb + cc][0])
				{
					q.push({ ca,cb + cc,0 });
					check[ca][cb + cc][0] = true;
				}
			}
		}

		if (cc < c)
		{
			int need = c - cc;
			if (ca >= need)
			{
				if (!check[ca - need][cb][c])
				{
					q.push({ ca - need, cb, c });
					check[ca - need][cb][c] = true;
				}
			}
			else
			{
				if (!check[0][cb][cc + ca])
				{
					q.push({ 0, cb, cc + ca });
					check[0][cb][cc + ca] = true;
				}
			}

			if (cb >= need)
			{
				if (!check[ca][cb - need][c])
				{
					q.push({ ca,cb - need,c });
					check[ca][cb - need][c] = true;
				}
			}
			else
			{
				if (!check[ca][0][cc + cb])
				{
					q.push({ ca,0,cc + cb });
					check[ca][0][cc + cb] = true;
				}
			}
		}
	}

	sort(v.begin(), v.end());

	v.erase(unique(v.begin(), v.end()), v.end());

	for (int num : v)
	{
		cout << num << " ";
	}
}

