#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0, col = board.size(), row = board[0].size(), len = min(col ,row);
    
    vector<vector<int>> dp(col+1, vector<int>(row+1,0));
    for(int x=1; x<col+1; x++)
    {
        for(int y=1; y<row+1; y++)
        {
            if(board[x-1][y-1] == 1)
            {
                dp[x][y] = min(min(dp[x-1][y-1], dp[x-1][y]),dp[x][y-1]) + 1;
                answer = max(answer, dp[x][y]);
            }
        }
    }

    return answer * answer;
}