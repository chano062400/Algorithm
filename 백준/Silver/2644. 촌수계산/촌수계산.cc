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
using namespace std;

int n, m, a, b, res =0;
vector<int> v[101];
bool visited[101];

void dfs(int cur, int cnt)
{
    visited[cur] = 1;

    if (cur == b)
    {
        res = cnt;
        return;
    } 

    for (int i = 0; i < v[cur].size(); i++)
    {
        if(!visited[v[cur][i]]) dfs(v[cur][i], cnt + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    
    cin >> a >> b;
    
    cin >> m;
    
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    dfs(a, 0);

    if (res == 0) cout << -1;
    else cout << res;

}
