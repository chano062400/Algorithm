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

vector<int> v[100001];
bool visited[100001];
int order[100001], cnt = 1;

void dfs(int cur)
{
    if (visited[cur]) return;

    visited[cur] = 1;
    order[cur] = cnt++;

    for (int i = 0; i < v[cur].size(); i++)
    {
        dfs(v[cur][i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;

    memset(visited, 0, sizeof(visited));
    memset(order, 0, sizeof(order));

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

    dfs(r);

    for (int i = 1; i <= n; i++)
    {
        cout << order[i] << '\n';
    }
}
