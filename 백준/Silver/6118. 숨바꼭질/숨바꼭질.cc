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

int n, m, mx = 0;
int dist[20001];
vector<int> v[50001];

void dijkstra()
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    dist[1] = 0;

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
                mx = max(mx, nextdist);
                dist[next] = nextdist;
                pq.push({ nextdist, next });
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int start, end;
        cin >> start >> end;
        v[start].push_back(end);
        v[end].push_back(start);
    }

    fill(dist, dist + 20001, 987654321);

    dijkstra();

    int mnidx = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == mx)
        {
            if (mnidx == 0) mnidx = i;
            cnt++;
        }
    }

    cout << mnidx << " " << dist[mnidx] << " " << cnt;
}
