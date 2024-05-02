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

int dp[101][101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a, b, c;
    cin >> a >> b >> c;

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= a.length(); i++)
    {
        for (int j = 1; j <= b.length(); j++)
        {
            for (int h = 1; h <= c.length(); h++)
            {
                if (a[i - 1] == b[j - 1] && b[j - 1] == c[h - 1])
                {
                    dp[i][j][h] = dp[i - 1][j - 1][h - 1] + 1;
                }
                else
                {
                    dp[i][j][h] = max(max(dp[i - 1][j][h], dp[i][j - 1][h]), dp[i][j][h - 1]);
                }
            }
        }
    }

    cout << dp[a.length()][b.length()][c.length()];
}
   