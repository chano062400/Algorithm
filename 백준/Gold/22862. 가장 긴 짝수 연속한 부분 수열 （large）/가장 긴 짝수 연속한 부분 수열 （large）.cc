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

    int n, k, res= 0;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int l = 0, r = 0, odd = 0, len = 0;
    while (r < n)
    {
        if (len - odd <= k)
        {
            if (v[r] % 2 == 0)
            {
                ++odd;
            }
            ++r;
            ++len;
        }
        else if(len - odd > k)
        {
            if (v[l] % 2 == 0)
            {
                --odd;
            }
            ++l;
            --len;
        }

        res = max(res, odd);
    }

    cout << res;
}