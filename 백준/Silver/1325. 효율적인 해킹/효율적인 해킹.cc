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

int n, m,cnt;
vector<int> v[10001];
bool visited[10001];

void dfs(int idx)
{
    visited[idx] = 1;

    if (v[idx].size() == 0) return;
    
    for (int i = 0; i < v[idx].size(); i++)
    {
        int next = v[idx][i];

        if (!visited[next])
        {
            cnt++;
            visited[next] = 1;
            dfs(next);
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;



    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }
 
    vector<int> num(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cnt = 0;
        dfs(i);
        num[i] = cnt;
        memset(visited, 0, sizeof(visited));
    }

    auto mx = *max_element(num.begin(), num.end());
    
    vector<int> canhack;
    
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] == mx) canhack.push_back(i);
    }
    
    sort(canhack.begin(), canhack.end());
    
    for (auto s : canhack) cout << s << " ";
}