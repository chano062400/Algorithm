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

int t,m, dp[10001], coin[21];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    cin >> t;
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        memset(coin, 0, sizeof(coin));

        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> coin[i];
        }
        
        cin >> m;

        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = coin[i]; j <= m; j++)
            {
                dp[j] += dp[j - coin[i]];
            }
        }

         cout << dp[m] << '\n';
    }
};

