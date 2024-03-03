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

int n, m, k, x;
vector<int> v[300001];
int dist[300001];

void dijkstra(int start)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});
    dist[start] = 0;

    while (!pq.empty())
    {
        int curdist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (curdist > dist[cur]) continue;

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i];
            int nextdist = curdist + 1;

            if (nextdist < dist[next])
            {
                dist[next] = nextdist;
                pq.push({ nextdist,next });
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k >> x;

    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        v[s].push_back(e);
    }

    fill(dist, dist + 300001, 9876543210);

    dijkstra(x);

    bool canfind = false;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == k)
        {
            if (!canfind) canfind = true;
            cout << i << '\n';
        }
    }

    if (!canfind) cout << -1;
}
