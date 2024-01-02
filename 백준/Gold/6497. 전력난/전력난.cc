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
using namespace std;

int m, n, e1, e2, sum, res, cnt;
vector<pair<int,pair<int,int>>> v;
int parent[200001];

int Find(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x < y) parent[y] = x;
    else parent[x] = y;
}

bool sameparent(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x == y) return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    while (1)
    {
        cin >> m >> n;
        if (m == 0 && n == 0) break;

        v.clear();

        for (int i = 0; i < m; i++)  parent[i] = i;

        sum = 0;
        res = 0;
        cnt = 0;

        for (int i = 0; i < n; i++)
        {
            int start, end, dist;
            cin >> start >> end >> dist;
            v.push_back({ dist,{start,end} });
            sum += dist;
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++)
        {
            if (!sameparent(v[i].second.first, v[i].second.second))
            {
                Union(v[i].second.first, v[i].second.second);
                res += v[i].first;
            }
        }

        cout << sum - res << '\n';

    }
}
