#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

bool visited[10001];
int parent[10001];
vector<pair<int,pair<int, int>>> vec;
int cnt = 0;
int v, e;


int Find(int x)
{
    if (parent[x] == x) return x;

    else
    {
        return parent[x] = Find(parent[x]);
    }
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    parent[y] = x;
}

bool sameparent(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x == y) return true;
    else return false;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

  
    cin >> v >> e;

  
    for (int i = 0; i < e; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        
        vec.push_back(make_pair(cost, make_pair(from, to)));
    }

    sort(vec.begin(), vec.end());

    for (int i = 1; i <= v; i++) parent[i] = i;
    
    for (int i = 0; i < vec.size(); i++)
    {
        if (!sameparent(vec[i].second.first, vec[i].second.second))
        {
            Union(vec[i].second.first, vec[i].second.second);
            cnt += vec[i].first;
        }
    }

    cout << cnt;
}           
