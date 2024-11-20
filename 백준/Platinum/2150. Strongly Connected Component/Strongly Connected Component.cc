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

int v, e, order, scc_count;
vector<int> adj[10001], discover(10001, -1), scc(10001, -1);
vector<vector<int>> sccs;
stack<int> st;
bool visited[10001];

int dfs(int cur)
{
    int min_order = discover[cur] = order++;
    st.push(cur);

    for (auto next : adj[cur])
    {
        if (discover[next] == -1)
        {
            min_order = min(min_order, dfs(next));
        }
        else if (scc[next] == -1)
        {
            min_order = min(min_order, discover[next]);
        }
    }

    if (min_order == discover[cur])
    {
        vector<int> temp;
        while (1)
        {
            int num = st.top();
            st.pop();
            scc[num] = scc_count;
            temp.push_back(num);
            if (num == cur) break;
        }
        sort(temp.begin(), temp.end());
        sccs.push_back(temp);
        scc_count++;
    }
    return min_order;
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
    }

    for (int i = 1; i <= v; i++)
    {
        if (discover[i] == -1)
        {
            dfs(i);
        }
    }

    cout << sccs.size() << '\n';
    sort(sccs.begin(), sccs.end());
    for (auto scc : sccs)
    {
        for (auto num : scc)
        {
            cout << num << " ";
        }
        cout << -1 << '\n';
    }
}
