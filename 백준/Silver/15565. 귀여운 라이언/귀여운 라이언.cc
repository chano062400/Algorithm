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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int s = 0, e = 0, len = 1e6 + 1, cnt[3] = { 0,0,0 };
    cnt[v[0]]++;

    while (s <= e && e < n)
    {
        if (cnt[1] < k)
        {
            if (e == n - 1) break;
            cnt[v[++e]]++;
        }
        else
        {
            len = min(len, e - s + 1);
            cnt[v[s++]]--;
        }
    }

    len == 1e6 + 1 ? cout << -1 : cout << len;
}
