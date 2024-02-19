#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stack>
#include <regex>
#include <map>
#include <cstdlib>
#include <list>
#include <sstream>
#include <bitset>
#include <set>
using namespace std;

int n, m, r, dep =1;
vector<int> v[100001];
int visited[100001];


void dfs(int cur)
{
    if (visited[cur] != 0) return;

    visited[cur] = dep++;

    for (int i = 0; i < v[cur].size(); i++)
    {
        int next = v[cur][i];
        dfs(next);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> r;
    
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(visited, 0, sizeof(visited));

    for (int i = 1; i <= n; i++)
    {
        sort(v[i].begin(), v[i].end());
    }

    dfs(r);

    for (int i = 1; i <= n; i++)
    {
        cout << visited[i] << '\n';
    }
}
