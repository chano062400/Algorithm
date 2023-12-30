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

int c, n;
int cost[21], customer[21];
int dp[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> c >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i] >> customer[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 100000; j++)
        {
            if (j - cost[i] >= 0)
            {
                dp[j] = max(dp[j], dp[j - cost[i]] + customer[i]);
            }
        }
    }

    for (int i = 1; i <= 100000; i++)
    {
        if (dp[i] >= c)
        {
            cout << i;
            break;
        }
    }
}
