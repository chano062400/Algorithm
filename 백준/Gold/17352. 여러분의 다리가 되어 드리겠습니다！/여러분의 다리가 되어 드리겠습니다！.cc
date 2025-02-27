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

int n;
int parent[300001];

int Find(int x)
{
    if (parent[x] == x) return x;
    return Find(parent[x]);
}

bool IsSameParent(int x, int y)
{
    return Find(x) == Find(y);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x < y)
    {
        parent[y] = x;
    }
    else if (x > y)
    {
        parent[x] = y;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < n - 2; i++)
    {
        int x, y;
        cin >> x >> y;
        if (IsSameParent(x, y)) continue;
        Union(x, y);
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j || IsSameParent(i,j)) continue;
            cout << i << " " << j;
            return 0;
        }
    }
}