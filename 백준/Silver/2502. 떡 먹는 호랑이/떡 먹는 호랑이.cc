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

int d, k;
int dp[31][3] = {};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> d >> k;

    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[2][1] = 0;
    dp[2][2] = 1;

    for (int i = 3; i <= d; i++)
    {
        dp[i][1] = dp[i - 2][1] + dp[i - 1][1];
        dp[i][2] = dp[i - 2][2] + dp[i - 1][2];
    }

    int one = dp[d][1], two = dp[d][2];
    
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i * one + j * two == k)
            {
                cout << i << '\n';
                cout << j << '\n';
                return 0;
            }
        }
    }
}
