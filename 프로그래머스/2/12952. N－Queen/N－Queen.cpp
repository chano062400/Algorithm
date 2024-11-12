#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,1,-1,-1};
int dy[] = {1,-1,-1,1};

void back(int r, int n, int& answer, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2)
{
    if(r == n)
    {
        ++answer;
        return;
    }
    
    for(int c = 0; c < n; c++)
    {
        if(col[c] || diag1[r + c] || diag2[r - c + n - 1]) continue;
        
        col[c] = diag1[r + c] = diag2[r - c + n - 1] = true;
        back(r + 1, n , answer, col , diag1, diag2);
        col[c] = diag1[r + c] = diag2[r - c + n - 1] = false;
    }
}

int solution(int n) {
    int answer = 0;
    vector<bool> col(n, 0);
    vector<bool> diag1(2 * n - 1, 0);
    vector<bool> diag2(2 * n - 1, 0);
    back(0, n, answer, col, diag1, diag2);
    return answer;
}