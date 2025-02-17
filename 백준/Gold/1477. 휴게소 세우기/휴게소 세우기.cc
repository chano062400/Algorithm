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

    int n, m, l;
    cin >> n >> m >> l;
    vector<int> v(n, 0), dist;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if (n == 0)
    {
        dist.push_back(l);
    }
    else
    {
        sort(v.begin(), v.end());

        dist.push_back(v[0]);
        for (int i = 1; i < n; i++)
        {
            dist.push_back(v[i] - v[i - 1]);
        }
        dist.push_back(l - v[n - 1]);

        sort(dist.begin(), dist.end(), greater<int>());
    }

    int s = 1, e = 1000, res = 1000;
    while (s <= e)
    {
        int mid = ceil((double(s) + double(e)) / double(2));

        int cnt = 0;
        for (int i = 0; i < dist.size(); i++)
        {
            int cur = dist[i];
            if (cur <= mid) break;

            for (int j = 2; ; j++)
            {
                if (ceil(double(cur) / double(j) <= double(mid)))
                {
                    cnt += j - 1;
                    break;
                }
            }
        }

        if (cnt > m)
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