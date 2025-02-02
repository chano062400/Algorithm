#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0, size = sticker.size();
    vector<int> dp(size, 0);
    if(sticker.size() == 1) return sticker[0];
    
    // 첫번째 스티커를 뜯은 경우.
    dp[0] = dp[1] = sticker[0];
    for(int i = 2; i < size - 1; i++)
    {
        dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
        answer = max(answer, dp[i]);
    }
    // 두번째 스티커를 뜯은 경우.
    dp[0] = 0;
    dp[1] = sticker[1];
    for(int i = 1; i < size; i++)
    {
        dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
        answer = max(answer, dp[i]);
    }
    
    return answer;
}