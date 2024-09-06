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

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    vector<pair<int,int>> v(n + 1);
    vector<long long> sum(n+1,0);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    
    sort(v.begin() + 1, v.end());

    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + v[i].second;
    }

    int start = 1, end = n, res = 1e9;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (sum[mid] >= sum[n] - sum[mid])
        {
            res = min(res, v[mid].first);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << res;


}

