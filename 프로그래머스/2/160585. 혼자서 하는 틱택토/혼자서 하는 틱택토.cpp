#include <bits/stdc++.h>

using namespace std;

bool Check(const vector<string>& board, char player)
{
    // 가로, 세로
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }

    // 대각선
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    
    return false;
}


int solution(vector<string> board) {
    int answer = 1, OCnt = 0, XCnt = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == 'O') OCnt++;
            else if(board[i][j] == 'X') XCnt++;
        }
    }

    bool OWin = Check(board, 'O');
    bool XWin = Check(board, 'X');
    
    if(XCnt > OCnt || OCnt - XCnt > 1) return 0;
    
    if(OWin && XWin) return 0;
    
    if(OWin) return OCnt == XCnt + 1 ? 1 : 0;
    
    if(XWin) return OCnt == XCnt ? 1 : 0;
    return 1;
}