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

int n, m, r;
int dep[100001];
vector<int> v[100001];

void dfs(int cur, int depth)
{
    dep[cur] = depth;
    
    for (int i = 0; i < v[cur].size(); i++)
    {
        int next = v[cur][i];
        if (dep[next] != -1) continue;
        dfs(next, depth + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> m >> r;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for (int i = 0; i < n; i++)
    {
        sort(v[i].begin(), v[i].end());
    }

    memset(dep, -1, sizeof(dep));

    dfs(r, 0);
    
    for (int i = 1; i <= n; i++)
    {
        cout << dep[i] << '\n';
    }

};

