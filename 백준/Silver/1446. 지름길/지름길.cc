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
using namespace std;

int n, d, res=0;
int dist[10001];
vector<pair<int, int>> v[10001];

void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,start });

    while (!pq.empty())
    {
        int curdist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].second;
            int nextdist = curdist + v[cur][i].first;
            
            if (nextdist < dist[next])
            {
                dist[next] = nextdist;
                pq.push({ nextdist, next });
            }
        }

        if (cur + 1 <= d && dist[cur + 1] > curdist)
        {
            dist[cur + 1] = curdist + 1;
            pq.push({ curdist + 1, cur + 1 });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> d;
    
    for (int i = 0; i < n; i++)
    {
        int start, end, dist;
        cin >> start >> end >> dist;
        if (end > d || dist > end - start) continue;
        v[start].push_back({dist, end});
    }
    
    fill(dist, dist + 10001, 987654321);

    dijkstra(0);

    cout << dist[d];
}
