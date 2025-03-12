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

int n, m;
int res[101][35];
bool cantgo[101];

int dfs(int day, int coupon)
{
    if (day > n) return 0;

    if (res[day][coupon] != INT_MAX) return res[day][coupon];

    if (cantgo[day])
    {
        return res[day][coupon] = dfs(day + 1, coupon);
    }

    if (coupon >= 3)
    {
        res[day][coupon] = dfs(day + 1, coupon - 3);
    }
    
    res[day][coupon] = min(res[day][coupon], dfs(day + 1, coupon) + 10000);
    res[day][coupon] = min(res[day][coupon], dfs(day + 3, coupon + 1) + 25000);
    res[day][coupon] = min(res[day][coupon], dfs(day + 5, coupon + 2) + 37000);

    return res[day][coupon];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 34; j++)
        {
            res[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int day;
        cin >> day;
        cantgo[day] = true;
    }

    cout << dfs(1, 0);
}
