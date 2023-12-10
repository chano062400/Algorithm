#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    for(int i = 0; i < moves.size(); i++)
    {
        for(int j = 0; j < board.size(); j++)
        {
            int row = moves[i] - 1 , doll = board[j][row];
            if(doll != 0)
            {
                if(!st.empty() && st.top() == doll) st.pop(), answer+= 2;
                else if(st.empty() || st.top() != doll) st.push(doll);
                board[j][row] = 0;
                break;
            }
        }

        
    }
    
    return answer;
}