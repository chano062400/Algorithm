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

int n, m, k;
int dp[16][16];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;

    dp[1][1] = 1;
    if (k == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1];
            }
        }

        cout << dp[n][m];
    }
    else
    {
        int num = 1, kx = 0, ky = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (num == k)
                {
                    kx = i; ky = j;
                }
                num++;
            }
        }

        for (int i = 1; i <= kx; i++)
        {
            for (int j = 1; j <= ky; j++)
            {
                dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1];
            }
        }

        int res = dp[kx][ky];
        dp[kx][ky] = 1;

        for (int i = kx; i <= n; i++)
        {
            for (int j = ky; j <= m; j++)
            {
                if (i == kx && j == ky) continue;
                dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1];
            }
        }

        cout << res * dp[n][m];
    }

};

