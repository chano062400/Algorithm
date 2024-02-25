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

int n, s, m, res = -1;
int dp[51][1001], num[51];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }

    memset(dp, -1, sizeof(dp));
    dp[0][s] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            // 전 곡 볼륨의 최대, 최소 중에 j있다면
            if (dp[i - 1][j] == 1)
            {
                if (j + num[i] <= m)
                {
                    dp[i][j + num[i]] = 1;
                }

                if (j - num[i] >= 0)
                {
                    dp[i][j - num[i]] = 1;
                }
            }
        }
    }
    
    for (int i = 0; i <= m; i++)
    {
        if (dp[n][i] == 1)
        {
            res = max(res, i);
        }
    }

    cout << res;
}
