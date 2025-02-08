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

    int n, m, res = 0;
    cin >> n >> m;

    vector<string> v(n, "");
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        auto it = lower_bound(v.begin(), v.end(), str);
        if (it == v.end()) continue;
        
        int idx = it - v.begin();
        bool flag = true;
        for (int j = 0; j < str.length(); j++)
        {
            if (v[idx][j] != str[j])
            {
                flag = false;
                break;
            }
        }
        if (flag) res++;
    }
    cout << res;
}