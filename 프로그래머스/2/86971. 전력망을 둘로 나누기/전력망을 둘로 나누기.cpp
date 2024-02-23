#include <bits/stdc++.h>
using namespace std;

bool visited[101];
vector<int> v[101];
int dep;

void dfs(int cur, int ignore)
{
    visited[cur] = 1;
    dep++;
    
    for(int i=0; i<v[cur].size(); i++)
    {
        int next = v[cur][i];
        if(!visited[next] && next != ignore)
        {
            visited[next] = 1;
            dfs(next, ignore);
        }
    }

}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    for(int i=0; i<wires.size(); i++)
    {
        int x = wires[i][0];
        int y = wires[i][1];
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for(int i=0; i<wires.size(); i++)
    {
        int x = wires[i][0];
        int y = wires[i][1];
        
        dep =0;   
        memset(visited,0,sizeof(visited));
        dfs(x, y);
        int dep1 = dep;    
        
        dep=0;
        memset(visited,0,sizeof(visited));
        dfs(y, x);
        int dep2 = dep;
        
        answer = min(answer, abs(dep2- dep1));

    }
    return answer;
}