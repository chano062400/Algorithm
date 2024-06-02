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
#include <unordered_map>
#include <numeric>
#include <memory>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long start = 0, end = pow(2,31) - 1, cnt, res = 0;
    while (start <= end)
    {
        long long mid = (start + end) / 2;

        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += v[i] / mid;
        }

        if (cnt >= k)
        {
            start = mid + 1;
            res = max(res, mid);
        }
        else end = mid - 1;
    }

    cout << res;
}
    