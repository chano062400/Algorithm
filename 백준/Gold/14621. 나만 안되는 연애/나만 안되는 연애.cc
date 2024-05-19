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

char mw[1001];
bool visited[1001];
int n, m, res = 0, cnt = 0;
vector<pair<int, int>> v[1001];

bool prim(int start)
{
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    visited[start] = 1;

    for (int i = 0; i < v[start].size(); i++)
    {
        int dist = v[start][i].first;
        int next = v[start][i].second;
        pq.push({ dist,next });
    }

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (visited[cur]) continue;

        visited[cur] = 1;
        
        res += dist;

        if (++cnt == n - 1)
        {
            return true;
        }

        for (int i = 0; i < v[cur].size(); i++)
        {
            int nextdist = v[cur][i].first;
            int next = v[cur][i].second;
            pq.push({ nextdist, next });
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> mw[i];
    }

    for (int i = 0; i < m; i++)
    {
        int s, e, d;
        cin >> s >> e >> d;
        if (mw[s] != mw[e])
        {
            v[s].push_back({ d,e });
            v[e].push_back({ d,s });
        }
    }

    if (prim(1)) cout << res;
    else cout << -1;
}
  