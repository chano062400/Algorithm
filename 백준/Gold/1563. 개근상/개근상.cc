 #include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include "memory.h"
#include <set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
#include <limits.h>
#include <list>
using namespace std;

// 날짜 / 지각 / 연속 결석
long long dp[1001][2][3];

const int MOD = 1000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    dp[1][0][0] = dp[1][1][0] = dp[1][0][1] = 1;
    
    for (int i = 2; i <= n; i++)
    {
        dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
        dp[i][0][1] = dp[i - 1][0][0] % MOD;
        dp[i][0][2] = dp[i - 1][0][1] % MOD;
        dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % MOD;
        dp[i][1][1] = dp[i - 1][1][0] % MOD;
        dp[i][1][2] = dp[i - 1][1][1] % MOD;
    }

    cout << (dp[n][0][0] + dp[n][0][1] + dp[n][0][2] + dp[n][1][0] + dp[n][1][1] + dp[n][1][2]) % MOD;
}