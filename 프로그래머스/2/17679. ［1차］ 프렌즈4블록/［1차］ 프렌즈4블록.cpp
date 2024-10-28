#include <bits/stdc++.h>
using namespace std;

void check(int x, int y, const vector<string>& board, set<pair<int,int>>& deletepos)
{
    if (x + 1 == board.size() || y + 1 == board[0].length()) return;

    char block = board[x][y];
    char block1 = board[x][y + 1];
    char block2 = board[x + 1][y];
    char block3 = board[x + 1][y + 1];

    if (block == block1 && block == block2 && block == block3)
    {
        deletepos.insert({ x,y });
        deletepos.insert({ x,y+1 });
        deletepos.insert({ x+1,y });
        deletepos.insert({ x+1,y+1 });
    }
}

void down(int m, int n, vector<string>& board)
{
    for(int i = m - 1; i >= 0; i--)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            if(board[i][j] == '.')
            {
                int x = i - 1;
                while(x >= 0 && board[x][j] == '.') x--;
                if(x >= 0) swap(board[i][j], board[x][j]);
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    set<pair<int, int>> deletepos;
    while (1)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.') continue;
                check(i, j, board, deletepos);
            }
        }
        
        if (deletepos.size() > 0)
        {
            for (auto pos : deletepos)
            {
                board[pos.first][pos.second] = '.';
            }
            answer += deletepos.size();
            
            down(m, n, board);
            
            deletepos.clear();
        }
        else break;

    }
    return answer;
}