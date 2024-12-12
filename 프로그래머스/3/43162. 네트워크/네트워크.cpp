#include <bits/stdc++.h>
using namespace std;

void dfs(int cur, vector<bool>& visited, const vector<vector<int>>& computers)
{
    if(visited[cur]) return;
    visited[cur] = true;
    for(int i = 0; i < computers.size(); i++)
    {
        if(i == cur) continue;
        if(computers[cur][i])
        {
            dfs(i, visited, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n,0);
    
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i, visited, computers);
            answer++;
        }
    }
    
    return answer;
}