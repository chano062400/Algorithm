#include <iostream>
#include <vector>
using namespace std;

int dp[100001][4];

int solution(vector<vector<int> > land)
{
    int answer = 0;

    dp[0][0] = land[0][0];
    dp[0][1] = land[0][1];
    dp[0][2] = land[0][2];
    dp[0][3] = land[0][3];

    for (int i = 1; i < land.size(); i++)
    {
        dp[i][0] = max(dp[i-1][1] + land[i][0], dp[i][0]);
        dp[i][0] = max(dp[i-1][2] + land[i][0], dp[i][0]);
        dp[i][0] = max(dp[i-1][3] + land[i][0], dp[i][0]);
        dp[i][1] = max(dp[i-1][0] + land[i][1], dp[i][1]);
        dp[i][1] = max(dp[i-1][2] + land[i][1], dp[i][1]);
        dp[i][1] = max(dp[i-1][3] + land[i][1], dp[i][1]);
        dp[i][2] = max(dp[i-1][0] + land[i][2], dp[i][2]);
        dp[i][2] = max(dp[i-1][1] + land[i][2], dp[i][2]);
        dp[i][2] = max(dp[i-1][3] + land[i][2], dp[i][2]);
        dp[i][3] = max(dp[i-1][0] + land[i][3], dp[i][3]);
        dp[i][3] = max(dp[i-1][1] + land[i][3], dp[i][3]);
        dp[i][3] = max(dp[i-1][2] + land[i][3], dp[i][3]);
    }

    for(int i=0; i<4; i++)
    {
        if(answer < dp[land.size()-1][i])
        {
            answer = dp[land.size()-1][i];
        }
    }
    return answer;
}