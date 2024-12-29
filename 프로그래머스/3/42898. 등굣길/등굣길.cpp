#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m+1, 0));
    for(auto puddle : puddles) dp[puddle[1]][puddle[0]] = -1;
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(dp[i][j] == -1) continue;
            
            dp[i][j] = max(dp[i][j], max(0, dp[i-1][j]) + max(0, dp[i][j-1])) % MOD;
        }
    }
    return dp[n][m];
}