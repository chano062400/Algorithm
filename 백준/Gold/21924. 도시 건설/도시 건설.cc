 #include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include "memory.h"
#include <set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
#include <limits.h>
#include <list>
using namespace std;

vector<pair<int,pair<int,int>>> v;
int parent[100001];
int n, m;
long long total;

bool cmp(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2)
{
    if (p1.first == p2.first)
    {
        return p1.second.first < p2.second.first;
    }
    return p1.first < p2.first;
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
    
    if (x == y) return;
    if (x < y)
    {
        parent[y] = x;
    }
    else 
    {
        parent[x] = y;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b) swap(a, b);

        v.push_back({ c, {a, b}});
        total += c;
    }

    sort(v.begin(), v.end(), cmp);
    
    long long saving = 0;
    int cnt = 1;
    for (int i = 0; i < v.size(); i++)
    {
        int a = v[i].second.first;
        int b = v[i].second.second;
        int c = v[i].first;

        if (Find(a) != Find(b))
        {
            Union(a, b);
            saving += c;

            if (++cnt == n) break;
        }
    }
    
    cnt == n ? cout << total - saving : cout << -1;
}