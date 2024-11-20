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

int v, e;
vector<int> adj[10001], radj[10001];
stack<int> st;
bool visited[10001];

void dfs(int cur)
{
    if (visited[cur]) return;
    visited[cur] = true;
    for (auto next : adj[cur])
    {
        dfs(next);
    }
    st.push(cur);
}

void dfs(int cur, vector<int>& scc)
{
    if (visited[cur]) return;
    visited[cur] = true;
    for (auto next : radj[cur])
    {
        dfs(next, scc);
    }
    scc.push_back(cur);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    memset(visited, 0, sizeof(visited));
    vector<vector<int>> sccs;
    while (!st.empty())
    {
        vector<int> scc;
        int cur = st.top();
        st.pop();
        if (!visited[cur])
        {
            dfs(cur, scc);

            sort(scc.begin(), scc.end());

            sccs.push_back(scc);
        }
    }

    sort(sccs.begin(), sccs.end());
    cout << sccs.size() << '\n';
    for (auto scc : sccs)
    {
        for (auto num : scc)
        {
            cout << num << " ";
        }
        cout << -1 << '\n';
    }
}
