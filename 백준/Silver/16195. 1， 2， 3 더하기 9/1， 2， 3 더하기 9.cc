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

#define MAX 1000000009

int dp[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    memset(dp, 0, sizeof(dp));
    dp[1][1] = dp[2][1] = dp[3][1] = 1;
    dp[2][2] = 2;
    dp[3][2] = 3;
    dp[3][3] = 4;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = i + 1; j <= 1000; j++)
        {
            dp[i][j] = dp[i][j - 1];
        }
    }

    for (int i = 4; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            if (j > i)
            {
                dp[i][j] = dp[i][j - 1];
            }
            else
            {
                dp[i][j] = (((dp[i - 1][j - 1] + dp[i - 2][j - 1]) % MAX) + dp[i - 3][j - 1]) % MAX;
            }
        }
    }

    while (t--)
    { 
        int n, m;
        cin >> n >> m;

        cout << dp[n][m] << '\n';
    }
}
  