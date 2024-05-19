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

int parent[1001];
char mw[1001];
int n, m, res = 0, cnt = 0;

int Find(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

bool IsSameParent(int x, int y)
{
    x = Find(x);
    y = Find(y);

    return x == y;
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x >= y)
    {
        parent[x] = y;
    }
    else
    {
        parent[y] = x;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> m;

    for (int i = 1; i <= n; i++) parent[i] = i;

    for (int i = 1; i <= n; i++)
    {
        cin >> mw[i];
    }

    vector < pair<int, pair<int, int>>> v;
    for (int i = 0; i < m; i++)
    {
        int s, e, d;
        cin >> s >> e >> d;
        v.push_back({d, { s, e} });
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        int start = v[i].second.first;
        int end = v[i].second.second;
        int dist = v[i].first;
        if (!IsSameParent(start, end) && mw[start] != mw[end])
        {
            Union(start, end);
            res += dist;
            if (++cnt == n - 1)
            {
                cout << res;
                return 0;
            }
        }
    }
     
    cout << -1;
}
  