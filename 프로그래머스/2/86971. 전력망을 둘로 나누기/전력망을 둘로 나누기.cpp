#include <bits/stdc++.h>
using namespace std;
bool visited[101];
vector<int> v[101];


int dfs(int cur, int ignore, int depth)
{
    visited[cur] = 1;

    int dep = 1;
    for (int i = 0; i < v[cur].size(); i++)
    {
        int next = v[cur][i];
        if (!visited[next] && next != ignore)
        {
            visited[next] = 1;
            dep += dfs(next, ignore, depth+1);
        }
    }

    return dep;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    for (int i = 0; i < wires.size(); i++)
    {
        int x = wires[i][0];
        int y = wires[i][1];

        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (int i = 0; i < wires.size(); i++)
    {
        int x = wires[i][0];
        int y = wires[i][1];

        memset(visited, 0, sizeof(visited));    
        int dep1 = dfs(x, y, 0);

        memset(visited, 0, sizeof(visited));
        int dep2 = dfs(y, x, 0);

        answer = min(answer, abs(dep2 - dep1));

    }
    return answer;
}