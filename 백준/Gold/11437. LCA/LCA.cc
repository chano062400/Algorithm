#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "memory.h"
#include <set>
#include <unordered_set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
#include <limits.h>
#include <list>
using namespace std;

const int MAX = 50001;
// 2 ^ 16 = 65536
const int MAX_LOG = 17;
int n, m;
vector<int> v[MAX];
int depth[MAX];
int parent[MAX][MAX_LOG];

void dfs(int cur, int dep, int par)
{
    depth[cur] = dep;
    parent[cur][0] = par;

    for (int next : v[cur])
    {
        if (next == par) continue;
        dfs(next, dep + 1, cur);
    }
}

void connect()
{
    for (int k = 1; k < MAX_LOG; k++)
    {
        for (int cur = 1; cur <= n; cur++)
        {
            int par = parent[cur][k - 1];
            if (par == -1)
            {
                parent[cur][k] = -1;
            }
            else
            {
                // cur의 두번째(parent[cur][1]) = 부모는 cur의 첫번째 부모의 부모(parent[parent[cur][0]][0]).
                parent[cur][k] = parent[par][k - 1];
            }
        }
    }
}

int lca(int a, int b)
{
    // a의 깊이가 더 크도록 함.
    if (depth[a] < depth[b])
    {
        swap(a, b);
    }

    int diff = depth[a] - depth[b];
    // a를 위로 올리면서 깊이를 맞춤.
    for (int i = 0; diff != 0; i++)
    {
        if (diff % 2) a = parent[a][i];
        diff /= 2;
    }

    if (a == b) return a;

    // 두 노드가 같아질 때까지 올림.
    // 같은 조상 바로 밑까지 올린 후, 마지막에 한 번 더 부모를 구하면 LCA가 됨.
    for (int i = MAX_LOG - 1; i >= 0; i--)
    {
        if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    memset(parent, -1, sizeof(parent));
    memset(depth, -1, sizeof(depth));

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1, 0, -1);

    connect();

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}