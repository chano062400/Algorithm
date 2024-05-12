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

int n, m, s, e;
vector<int> v[300001];
bool visited[300001];

int bfs()
{
    queue<pair<int, int>> q;
    q.push({ s,0 });

    while (!q.empty())
    {
        int cur = q.front().first;
        int curtime = q.front().second;
        q.pop();

        if (cur == e)
        {
            return curtime;
        }

        if (cur + 1 <= 300000 && !visited[cur + 1])
        {
            visited[cur + 1] = 1;
            q.push({ cur + 1,curtime + 1 });
        }

        if (cur - 1 >= 1 && !visited[cur - 1])
        {
            visited[cur - 1] = 1;
            q.push({ cur - 1,curtime + 1 });
        }

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i];
            if (next <= 300000 && !visited[next])
            {
                visited[next] = 1;
                q.push({ next, curtime + 1 });
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> s >> e;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    cout << bfs();
}
   