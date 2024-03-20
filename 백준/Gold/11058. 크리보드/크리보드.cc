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
using namespace std;

int n;
long long dp[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;
    dp[6] = 6;

    for (int i = 7; i <= n; i++)
    {
        // A 출력한 경우
        dp[i] = dp[i - 1] + 1;
        for (int j = 3; j < i; j++)
        {
            dp[i] = max(dp[i - j] * (j - 1), dp[i]);
        }
    }

    cout << dp[n];
}
