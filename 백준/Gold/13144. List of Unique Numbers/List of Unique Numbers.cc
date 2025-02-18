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

int cnt[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i]; 
    }

    int s = 0, e = 0;
    long long res = 0;
    while (s < n && e < n)
    {
        if (cnt[v[e]] + 1 > 1)
        {
            --cnt[v[s++]];
        }
        if (cnt[v[e]] + 1 == 1)
        {
            res += e - s + 1;
            ++cnt[v[e++]];
        }
        
    }

    cout << res;
}