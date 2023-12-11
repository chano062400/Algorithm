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
using namespace std;

int n; 
long long mx = 0, mn = 987654321, total, res = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        v.push_back(num);
        mx = max(mx, num);
        mn = min(mn, num);
    }

    cin >> total;

    long long start = 1, end = mx, mid, sum;
    while (start <= end)
    {
        sum = 0;
        mid = (start + end) / 2;
        for (auto s : v) if (s > mid) sum += mid; else sum += s;

        if (sum > total) end = mid - 1;
        else
        {
            res = max(res,mid);
            start = mid + 1;
        }
    }

    cout << res;
}
