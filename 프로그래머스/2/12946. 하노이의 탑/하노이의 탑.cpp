#include <string>
#include <vector>

using namespace std;

void hanoi(vector<vector<int>>& answer, int n, int from, int bypass, int to)
{
    if(n == 1)
    {
        answer.push_back({from,to});
    }
    else
    {
        // n - 1개를 3번을 거쳐서 2번으로 옮긴다.
        hanoi(answer, n - 1, from, to, bypass);
        answer.push_back({from,to});
    
        // n - 1개를 1번을 거쳐서 3번으로 옮긴다.
        hanoi(answer, n - 1, bypass, from, to);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(answer, n, 1, 2, 3);
    return answer;
}