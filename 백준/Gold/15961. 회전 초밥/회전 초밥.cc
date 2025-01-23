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

int check[3000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, d, k, c, res = 0;
    cin >> n >> d >> k >> c;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int cnt = 1;
    check[c]++;
    for (int i = 0; i < k; i++)
    {
        if (check[v[i]] == 0)
        {
            cnt++;
        }
        check[v[i]]++;
    }

    res = max(res, cnt);

    for (int i = 1; i < n; i++)
    {
        if (check[v[i - 1]] - 1 == 0)
        {
            cnt--;
        }
        check[v[i - 1]]--;

        if (check[v[(i + k - 1) % n]] == 0)
        {
            cnt++;
        }
        check[v[(i + k - 1) % n]]++;

        res = max(res, cnt);
    }

    cout << res;
    return 0;
}