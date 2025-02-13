#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "memory.h"
#include <set>
#include <unordered_set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
#include <limits.h>
#include <list>
using namespace std;

int n, arr[33][33];
long long dp[33][33][3];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    dp[1][2][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((i == 1 && j == 1) || (i == 1 && j == 2)) continue;
            if (arr[i][j] == 1) continue;

            if (j - 1 >= 1 && arr[i][j - 1] == 0)
            {
                dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
            }
            if (i - 1 >= 1 && arr[i - 1][j] == 0)
            {
                dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
            }
            if (i - 1 >= 1 && j - 1 >= 1 && arr[i - 1][j] == 0 && arr[i][j - 1] == 0)
            {
                dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
            }
        }
    }

    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}