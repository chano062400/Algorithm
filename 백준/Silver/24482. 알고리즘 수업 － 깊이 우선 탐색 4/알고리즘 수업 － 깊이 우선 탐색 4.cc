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
#include <unordered_map>
#include <numeric>
#include <memory>
using namespace std;

int n, m, r;
vector<int> v[100001];
int depth[100001];
bool visited[100001];

void dfs(int cur, int dep)
{
    if (visited[cur]) return;
    visited[cur] = true;
    depth[cur] = dep;

    for (int i = 0; i < v[cur].size(); i++)
    {
        dfs(v[cur][i], dep + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> r;

    fill(depth, depth + n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(v[i].begin(), v[i].end(), greater<>());
    }

    dfs(r, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << depth[i] << '\n';
    }
}

