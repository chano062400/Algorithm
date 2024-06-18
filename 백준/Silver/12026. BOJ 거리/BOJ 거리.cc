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

int n;
vector<char> v(1001);
int dp[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    fill(dp, dp + 1001, 987654321);
    dp[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 'B')
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (v[j] == 'O')
                {
                    int dif = j - i;
                    dp[j] = min(dp[j], dp[i] + dif * dif);
                }
            }
        }
        else if (v[i] == 'O')
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (v[j] == 'J')
                {
                    int dif = j - i;
                    dp[j] = min(dp[j], dp[i] + dif * dif);
                }
            }
        }
        else if (v[i] == 'J')
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (v[j] == 'B')
                {
                    int dif = j - i;
                    dp[j] = min(dp[j], dp[i] + dif * dif);
                }
            }
        }
    }

    if (dp[n] == 987654321) cout << -1;
    else cout << dp[n];
}

    