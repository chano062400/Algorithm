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
long long dp[8] = {}, temp[8] = {};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        temp[0] = dp[1] + dp[2];
        temp[1] = dp[0] + dp[2] + dp[3];
        temp[2] = dp[0] + dp[1] + dp[3] + dp[4];
        temp[3] = dp[1] + dp[2] + dp[4] + dp[5];
        temp[4] = dp[2] + dp[3] + dp[5] + dp[6];
        temp[5] = dp[3] + dp[4] + dp[7];
        temp[6] = dp[4] + dp[7];
        temp[7] = dp[5] + dp[6];

        for (int j = 0; j < 8; j++)
        {
            dp[j] = temp[j] % 1000000007;
        }
    }

    cout << dp[0];
}
