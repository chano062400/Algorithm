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

int n, len, dp[21], res = 987654321;
vector<int> open, order;

void dfs(int open1, int open2, int index, int cnt)
{
    if (index == len)
    {
        res = min(res, cnt);
        return;
    }

    dfs(order[index], open2, index + 1, cnt + abs(open1 - order[index]));
    dfs(open1, order[index], index + 1, cnt + abs(open2 - order[index]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    open.resize(2);

    for (int i = 0; i < 2; i++)
    {
        cin >> open[i];
    }
    
    cin >> len;
    order.resize(len);
    for (int i = 0; i < len; i++)
    {
        cin >> order[i];
    }   

    dfs(open[0], open[1], 0, 0);

    cout << res;
}