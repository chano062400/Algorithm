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
long long dist[100001];
vector<pair<long long, int>> arr[100001];
bool cansee[100001];

void dijkstra(int start)
{
    priority_queue<pair<long long, int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0,start});
    dist[start] = 0;

    while (!pq.empty())
    {
        long long curdist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (curdist > dist[cur]) continue;

        for (int i = 0; i < arr[cur].size(); i++)
        {
            long long nextdist = curdist + arr[cur][i].first;
            int next = arr[cur][i].second;
            
            if (cansee[next] == 0 || (cansee[next] == 1 && next == n - 1))
            {
                if (nextdist < dist[next])
                {
                    dist[next] = nextdist;
                    pq.push({ nextdist, next });
                }
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    
    for (int i = 0; i < n; i++)
    {
        cin >> cansee[i];
        dist[i] = 9999999999;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long t;
        cin >> a >> b >> t;

		arr[a].push_back({ t,b });
		arr[b].push_back({ t,a });
    }

    dijkstra(0);

    if (dist[n-1] == 9999999999) cout << -1;
    else cout << dist[n-1];
};

