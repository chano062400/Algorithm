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

int n, k;
int dp[21][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    
    vector<pair<int, int>> v(21);
    for (int i = 1; i <= n-1; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    cin >> k;

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 987654321;
        dp[i][1] = 987654321;
    }

    dp[1][0] = 0;
    dp[2][0] = v[1].first;
    dp[3][0] = min(v[1].first + v[2].first, v[1].second);

    for (int i = 4; i <= n; i++)
    {
        // [i][0] - 매우 큰 점프 사용X / [i][1] - 매우 큰 점프 사용함
        dp[i][0] = min(dp[i - 1][0] + v[i - 1].first, dp[i - 2][0] + v[i - 2].second);
        dp[i][1] = min(min(dp[i - 1][1] + v[i - 1].first, dp[i - 2][1] + v[i - 2].second), dp[i - 3][0] + k);
    }

    cout << min(dp[n][0], dp[n][1]);
}

