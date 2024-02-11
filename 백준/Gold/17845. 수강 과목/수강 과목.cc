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
long long res =0, dp[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    vector<pair<int,int>> v;
    for (int i = 0; i < k; i++)
    {
        int l, t;
        cin >> l >> t;
        v.push_back({ l,t });
    }


    for (int i = 0; i < v.size(); i++)
    {
        for (int j = n; j >= v[i].second; j--)
        {
            dp[j] = max(dp[j], dp[j - v[i].second] + v[i].first);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        res = max(res, dp[i]);
    }
    
    cout << res;
};

