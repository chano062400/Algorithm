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
using namespace std;

int n, m, r, cnt =2;
vector<int> v[100001];
int order[100001];
bool visited[100001];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    order[start] = 1;
    visited[start] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i];
            if (!visited[next])
            {
                q.push(next);
                order[next] = cnt++;
                visited[next] = 1;
            }   
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> r;
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(v[i].begin(), v[i].end(), greater<int>());
    }
    memset(order, 0, sizeof(order));

    bfs(r);

    for (int i = 1; i <= n; i++)
    {
        cout << order[i] << '\n';
    }
}
