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

int v, e, p;
int dist[5001];
vector<pair<int,int>> arr[5001];

void dijkstra(int startdist, int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ startdist, start });

    while (!pq.empty())
    {
        int curdist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < arr[cur].size(); i++)
        {
            int nextdist = curdist + arr[cur][i].first;
            int next = arr[cur][i].second;

            if (nextdist < dist[next])
            {
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

    cin >> v >> e >> p;

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back({ c,b });
        arr[b].push_back({ c,a });
    }

    fill(dist, dist + 5001, 9876543210);

    dist[1] = 0;
    dijkstra(0,1);

    // 건우를 신경쓰지 않고 최단거리로 갔을 때 거리.
    int shortest = dist[v];
    
    // 건우가 있는 곳을 들렀을 때의 거리.
    int target = dist[p];
    
    fill(dist, dist + 5001, 9876543210);

    // 건우를 도와주고 목적지로 갔을 때 거리.
    dijkstra(target, p);
    
    if (shortest != dist[v])
    {
        cout << "GOOD BYE" << '\n';
    }
    else
    {
        cout << "SAVE HIM" << '\n';
    }
    
}
    