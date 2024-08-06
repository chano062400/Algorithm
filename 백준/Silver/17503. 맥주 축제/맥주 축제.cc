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

int n, m, k;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    long long res = 1e13;
    int mx = 0;
    vector<pair<long long, long long>> v;

    for (int i = 0; i < k; i++)
    {
        int s, l;
        cin >> s >> l;
        v.push_back({ s,l });
        mx = max(mx, l);
    }

    sort(v.begin(), v.end(), cmp);
    
    long long start = 1, end = mx;

    while (start <= end)
    {
        long long mid = (start + end) / 2;

        vector<int> v2;
        for (auto pair : v)
        {
            // 최소 레벨이 mid보다 높다면 탐색X
            if (pair.second > mid) break;

			v2.push_back(pair.first);
        }

        if (v2.size() < n)
        {
            start = mid + 1;
        }
        else
        {
            sort(v2.begin(), v2.end(), greater<>());

            long long sum = 0;
            for (int i=0; i < n; i++)
            {
                sum += v2[i];
            }

            if (sum < m)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
                res = min(res, mid);
            }
        }
    }

    if (res == 1e13) cout << -1;
    else cout << res;
}
