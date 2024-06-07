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

int n, m, cnt = 0;
vector<int> v[501];
bool visited[501];

void dfs(int cur, int depth)
{
    if (depth == 2) return;

    for (int i = 0; i < v[cur].size(); i++)
    {
        int next = v[cur][i];

        visited[next] = 1;
        dfs(next, depth + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1, 0);

    for (int i = 2; i <= n; i++)
    {
        if (visited[i]) cnt++;
    }

    cout << cnt;
}
    