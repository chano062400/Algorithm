#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007

int solution(int n) {
    vector<long long> dp(5001,0);
    dp[0] = 1;
    dp[2] = 3;
    for(int i = 4; i<=n; i+=2)
    {
        dp[i] = dp[i-2] * 3;
        for(int j = 4; j<=i; j+=2)
        {
            dp[i] += dp[i - j] * 2;
        }
        dp[i] = dp[i] % MOD;
    }
    return dp[n];
}