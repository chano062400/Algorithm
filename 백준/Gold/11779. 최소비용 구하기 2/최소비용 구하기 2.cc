#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory>

using namespace std;

int dist[1001], parent[1001];;
vector<pair<int, int>> v[1001];
int n, m;

void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,start });
    dist[start] = 0;
    
    while (!pq.empty())
    {
        int curdist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < curdist) continue;

        for (int i = 0; i < v[cur].size(); i++)
        {
            int nextdist = curdist + v[cur][i].first;
            int next = v[cur][i].second;

            if (nextdist < dist[next])
            {
                dist[next] = nextdist;
                parent[next] = cur;
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

    for (int i = 0; i < m; i++)
    {
        int s, e, d;
        cin >> s >> e >> d;
        v[s].push_back({ d,e });
    }

    for (int i = 1; i <= n; i++)
    {
        dist[i] = 987654321;
    }

    int sc, ec;
    cin >> sc >> ec;

    dijkstra(sc);

    cout << dist[ec] << '\n';

    vector<int> visited;
    visited.push_back(ec);
    while (visited.back() != sc)
    {
        visited.push_back(parent[visited.back()]);
    }
    cout << visited.size() << '\n';

    reverse(visited.begin(), visited.end());

    for (int i = 0; i < visited.size(); i++)
    {
        cout << visited[i] << " ";
    }

}