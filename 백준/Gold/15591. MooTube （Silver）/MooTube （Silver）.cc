 #include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include "memory.h"
#include <set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
#include <limits.h>
#include <list>
using namespace std;

#define MAX 987654321

int n, q;
vector<pair<int,int>> v[5001];
bool visited[5001];

int dfs(int cur, int usado, int k)
{
    int res = 0;
    for (int i = 0; i < v[cur].size(); i++)
    {
        int next = v[cur][i].second;
        int nextusado = v[cur][i].first;
        int minusado = min(usado, nextusado);

        if (minusado >= k && !visited[next])
        {
            visited[next] = true;
            res += dfs(next, minusado,  k) + 1;
            visited[next] = false;
        }
    }
    return res;
}

int main() 
{
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ c,b });
        v[b].push_back({ c,a });
    }

    for (int i = 1; i <= n; i++)
    {
        sort(v[i].begin(), v[i].end());
    }
    
    for (int i = 0; i < q; i++)
    {
        int a, b; 
        cin >> a >> b;

        visited[b] = true;
        cout << dfs(b, MAX, a) << '\n';
        visited[b] = false;
    }
}