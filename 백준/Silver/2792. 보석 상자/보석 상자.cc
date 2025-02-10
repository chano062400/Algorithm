#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "memory.h"
#include <set>
#include <unordered_set>
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
    
    int n, m, mx = 0;
    cin >> n >> m;
    vector<int> v(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
        mx = max(mx, v[i]);
    }

    int s = 1, e = mx, res = mx;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            cnt += v[i] / mid; 
            if (v[i] % mid) cnt++;
        }

        if (cnt > n)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
            res = min(res, mid);
        }
    }

    cout << res;
}