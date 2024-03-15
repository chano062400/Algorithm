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
using namespace std;

int a, b, n, m, res = 987654321;
vector<int> v[1001];
bool visited[1001];

void bfs(int start)
{
    queue<pair<int,int>> q;
    q.push({ 0,start });
    visited[start] = 1;

    while (!q.empty())
    {
        int cnt = q.front().first;
        int cur = q.front().second;
        q.pop();

        if (cur == b)
        {
            res = cnt;
            return;
        }

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i];
            if (!visited[next])
            {
                visited[next] = 1;
                q.push({ cnt + 1, next });
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> a >> b >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    memset(visited, 0, sizeof(visited));
    bfs(a);

    if (res == 987654321) cout << -1;
    else cout << res;
}
