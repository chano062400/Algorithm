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

long long n, RGB[1001][4], dp[1001][4], res = 100000000;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> RGB[i][1] >> RGB[i][2] >> RGB[i][3];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (i == j) dp[1][j] = RGB[1][j];
            else dp[1][j] = 1000000;
        }

        for (int h = 2; h <= n; h++)
        {
            dp[h][1] = RGB[h][1] + min(dp[h - 1][2], dp[h - 1][3]);
            dp[h][2] = RGB[h][2] + min(dp[h - 1][1], dp[h - 1][3]);
            dp[h][3] = RGB[h][3] + min(dp[h - 1][1], dp[h - 1][2]);
        }

        for (int g = 1; g <= 3; g++)
        {
            if (i == g) continue;
            res = min(res, dp[n][g]);
        }
    }

    cout << res;
};

