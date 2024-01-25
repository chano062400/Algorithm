#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stack>
#include <regex>
#include <map>
#include <cstdlib>
#include <list>
#include <sstream>
#include <bitset>
#include <set>
using namespace std;

int n, k;
long long character[1000001], res = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    long long mx = 0, mn = 100000001;
    for (int i = 1; i <= n; i++)
    {
        cin >> character[i];
        mx = max(mx, character[i]);
        mn = min(mn, character[i]);
    }

    long long start = mn, end = mx + k, req;
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        req = 0;

        for (int i = 1; i <= n; i++)
        {
            if (character[i] < mid) req += mid - character[i];
        }

        if (req > k) end = mid - 1;
        else
        {
            res = max(res, mid);
            start = mid + 1;
        }
    }

    cout << res;
};

