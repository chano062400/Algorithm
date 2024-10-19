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
int depth[100001];
vector<int> v[100001];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    depth[start] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i];
            if (depth[next] == -1)
            {
                depth[next] = depth[cur] + 1;
                q.push(next);
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++)
    {
        depth[i] = -1;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs(r);

    for (int i = 1; i <= n; i++)
    {
        cout << depth[i] << '\n';
    }
}