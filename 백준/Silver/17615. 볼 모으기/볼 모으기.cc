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

    int n, idx = 1, bcnt = 0, rcnt = 0, res = 0, resB = 0, resR = 0;
    cin >> n;
    string str;
    cin >> str;

    map<char, int> BR;
    for (int i = 0; i < n; i++)
    {
        BR[str[i]]++;
    }

    str.front() == 'B' ? bcnt = 1 : rcnt = 1;
    while (idx < n && str[idx] == str.front())
    {
        if (str[idx++] == 'B') bcnt++;
        else rcnt++;
    }

    resB = BR['B'] - bcnt;
    resR = BR['R'] - rcnt;
    res = min(resB, resR);

    idx = n - 2;
    str.back() == 'B' ? bcnt = 1 : rcnt = 1;
    while (idx >= 0 && str[idx] == str.back())
    {
        if (str[idx--] == 'B') bcnt++;
        else rcnt++;
    }

    resB = BR['B'] - bcnt;
    resR = BR['R'] - rcnt;
    res = min(res, min(resB, resR));

    cout << res;
}