#include <string>
#include <vector>
#include <memory.h>
using namespace std;

long long dp[2001];

long long solution(int n) {
    memset(dp,0,sizeof(dp));
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }
    return dp[n];
}