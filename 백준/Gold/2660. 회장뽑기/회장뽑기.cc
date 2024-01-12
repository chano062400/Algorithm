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
using namespace std;

int n, num[51];
bool visited[51];
vector<int> v[51];

void bfs(int start, int depth)
{
    queue<pair<int, int>> q;
    q.push({ start, depth });
    visited[start] = 1;

    int maxdepth = 0;
    while (!q.empty())
    {
        int cur = q.front().first;
        int curdepth = q.front().second;
        q.pop();

        maxdepth = max(maxdepth, curdepth);

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i];
            if (!visited[next])
            {
                q.push({ next, curdepth + 1 });
                visited[next] = 1;
            }
        }
    }

    num[start] = maxdepth;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    while (1)
    {
        int n1, n2;
        cin >> n1 >> n2;

        if (n1 == -1 && n2 == -1) break;
        
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    

    int mn = 987654321, cnt = 0;
    vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        
        bfs(i, 0);
        
        if (mn > num[i])
        {
            res.clear();
            mn = num[i];
            cnt = 1;
            res.push_back(i);
        }
        else if (mn == num[i])
        {
            res.push_back(i);
            cnt++;
        }

    }

    cout << mn << " " << res.size() << '\n';
    for (auto r : res) cout << r << " ";

};

