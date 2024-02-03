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

long long dp[1001][1001];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 2;
    dp[3][3] = 1;

    for (int i = 4; i <= 1000; i++)
    {
        for (int j = 2; j <= 1000; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1];
            dp[i][j] %= 1000000009;
        }
    }

    while (n--)
    {
        int a, b; 
        cin >> a >> b;
        cout << dp[a][b] << '\n';
    }
};

