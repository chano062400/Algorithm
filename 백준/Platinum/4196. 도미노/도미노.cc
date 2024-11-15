#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "memory.h"
#include <set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
using namespace std;

void dfs(int cur, const vector<vector<int>>& v, vector<bool>& visited, stack<int>& dominos)
{
    if (visited[cur]) return;
    visited[cur] = true;
    for (int i = 0; i < v[cur].size(); i++)
    {
        dfs(v[cur][i], v, visited, dominos);
    }
    dominos.push(cur);
}

void dfs2(int cur, const vector<vector<int>>& v, vector<bool>& visited)
{
    if (visited[cur]) return;
    visited[cur] = true;
    for (int i = 0; i < v[cur].size(); i++)
    {
        dfs2(v[cur][i], v, visited);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> v(n + 1);
        vector<bool> visited(n + 1, 0);
        stack<int> dominos;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
        }

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                dfs(i, v, visited, dominos);
            }
        }
        
        fill(visited.begin(), visited.end(), 0);

        int cnt = 0;
        while(dominos.size())
        {
            int domino = dominos.top();
            dominos.pop();
            if (!visited[domino])
            {
                ++cnt;
                dfs2(domino, v, visited);
            }
        }

        cout << cnt << '\n';
    }
}
