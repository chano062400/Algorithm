#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include "memory.h"

using namespace std;

#define INF 10001
vector<pair<int, int>> v[1003];
int dist[1003];
int n, m, start, End;

void dijkstra(int st)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push(make_pair(0, st));
    dist[st] = 0;

    while (!pq.empty())
    {
        int Ccost = pq.top().first;
        int Cur = pq.top().second;
        pq.pop();

        if (dist[Cur] < Ccost) continue; //이거 안해서 시간초과.

        for (int i = 0; i < v[Cur].size(); i++)
        {
            int NCost = Ccost + v[Cur][i].second;
            int Next = v[Cur][i].first;

            if (NCost < dist[Next])
            {
                dist[Next] = NCost;
                pq.push(make_pair(NCost, Next));
            }
        }
    }

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

   
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }

    cin >> start >> End;
    memset(dist, INF, sizeof(dist));

    dijkstra(start);

    cout << dist[End];
}           
