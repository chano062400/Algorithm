#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory>
#include <cmath>

using namespace std;

int n, m, parent[1001];
vector<pair<int, int>> pos(1001);
vector<pair<double,pair<int,int>>> v;

double getdist(pair<int,int> a, pair<int,int> b)
{
    long long dist1 = (long long) pow(b.first - a.first, 2);
    long long dist2 = (long long) pow(b.second - a.second, 2);
    return (double) sqrt(dist1 + dist2);
}

int Find(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x >= y)parent[y] = x;
    else parent[x] = y;
}

bool sameparent(int x, int y)
{
    return Find(x) == Find(y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> pos[i].first >> pos[i].second;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            double dist = getdist(pos[i], pos[j]);
            v.push_back({ dist,{i,j}});
        }
    }
    
    double res = 0.f;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        if(Find(a) != Find(b))
        { 
            Union(a, b);
        }
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
    cout << fixed;
    cout.precision(2);
    cout << res;
}