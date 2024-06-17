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

bool visited[1001];
int n;
vector<int> v(1001);

void bfs()
{
    queue<pair<int,int>> q;
    q.push({1,0});
    visited[1] = 1;

    while (!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == n)
        {
            cout << cnt;
            return;
        }

        int next = cur + v[cur];
        for (int i = cur; i <= next; i++)
        {
            if (i <= n && !visited[i])
            {
                q.push({ i,cnt + 1 });
                visited[i] = 1;
            }
        }
    }

    cout << -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    bfs();
}

    