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

int n, m, res = 0;
int dp[201] = {};
vector<pair<int, int>> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int day, page;
        cin >> day >> page;
        v.push_back({ day,page });
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = n; j >= v[i].first; j--)
        {
            dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        res = max(res, dp[i]);
    }
    cout << res;
}
