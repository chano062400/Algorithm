#include<bits/stdc++.h>

using namespace std;
int answer = -1; 
bool visited[8];

void dfs(int cnt, int health, vector<vector<int>> dungeons)
{
    answer = max(answer, cnt);
    
    for(int i=0; i<dungeons.size(); i++)
    {
        if(!visited[i] && health >= dungeons[i][0])
        {
            visited[i] = 1;
            dfs(cnt + 1, health - dungeons[i][1], dungeons);
            visited[i] = 0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) { 
    dfs(0,k,dungeons);
    return answer;
}