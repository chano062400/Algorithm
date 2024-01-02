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
using namespace std;

int dp[1000001], n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n;
    
    memset(dp, 0, sizeof(dp));

    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] += dp[i - 1];
        if (i % 2 == 0)
        {
            dp[i] += dp[i / 2];
            dp[i] %= 1000000000;
        }
    }

    cout << dp[n] % 1000000000;
}
