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

int n, m;
vector<pair<int,int>> v[5001];
int dist[5001];

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,start });

    while (!pq.empty())
    {
        int curdist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (curdist > dist[cur]) continue;

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].second;
            int nextdist = curdist + v[cur][i].first;

            if (dist[next] > nextdist)
            {
                pq.push({ nextdist, next });
                dist[next] = nextdist;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        v[s].push_back({c,e});
        v[e].push_back({c,s});
    }

    fill(dist, dist + 5001, 9876543210);

    int ts, te;
    cin >> ts >> te;

    dijkstra(ts);

    cout << dist[te];
};

