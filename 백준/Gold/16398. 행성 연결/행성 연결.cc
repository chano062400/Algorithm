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
using namespace std;

int n;
int parent[1001], arr[1001][1001];

int Find(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x == y) return;

    if (x < y) parent[x] = y;
    else parent[y] = x;
}

bool SameParent(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x == y) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) parent[i] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<pair<int, pair<int, int>>> v;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            v.push_back({ arr[i][j], {i,j} });
        }
    }

    sort(v.begin(), v.end());

    long long res = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (!SameParent(v[i].second.first, v[i].second.second))
        {
            Union(v[i].second.first, v[i].second.second);
            res += v[i].first;
        }
    }

    cout << res;
}
