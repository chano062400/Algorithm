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

vector<int> v[100001];
int p[100001], Size[100001];

void maketree(int cur, int parent)
{
	if (v[cur].size() == 0) return;

	for (int i = 0; i < v[cur].size(); i++)
	{
		int next = v[cur][i];
		if (p[next] != cur && p[next] == -1)
		{
			p[next] = cur;
			maketree(next, cur);
		}
	}
}

void countsubtree(int cur)
{
	if (v[cur].size() == 0) return;

	Size[cur] = 1;
	for (int i = 0; i < v[cur].size(); i++)
	{
		int next = v[cur][i];
		if (p[next] == cur)
		{
			countsubtree(next);
		}
	}
	if(p[cur] != cur) Size[p[cur]] += Size[cur];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, r, q;
	cin >> n >> r >> q;

	for (int i = 1; i <= n; i++)
	{
		p[i] = -1;
	}
	p[r] = r;

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	maketree(r, r);
	countsubtree(r);

	for (int i = 0; i < q; i++)
	{
		int num;
		cin >> num;

		cout << Size[num] << '\n';
	}
}

