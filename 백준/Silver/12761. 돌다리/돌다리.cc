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

int a, b, n, m, res = 987654321;
bool visited[100001];

void bfs(int start)
{
    queue<pair<int,int>> q;
    q.push({ 0,start });

    while (!q.empty())
    {
        int cnt = q.front().first;
        int cur = q.front().second;
        q.pop();

        if (cur == n)
        {
            res = min(res, cnt);
            return;
        }

        if (cur + 1 > 0 && cur + 1 < 100000 && !visited[cur + 1])
        {
            visited[cur + 1] = true;
            q.push({ cnt + 1, cur + 1 });
        }

        if (cur - 1 > 0 && !visited[cur - 1])
        {
            visited[cur - 1] = true;
            q.push({ cnt + 1, cur - 1 });
        }

        if (cur + a > 0 && cur + a < 100000 && !visited[cur + a])
        {
            visited[cur + a] = true;
            q.push({ cnt + 1, cur + a });
        }

        if (cur - a > 0 && !visited[cur - a])
        {
            visited[cur - a] = true;
            q.push({ cnt + 1, cur - a });
        }
        
        if (cur + b > 0 && cur + b < 100000 && !visited[cur + b])
        {
            visited[cur + b] = true;
            q.push({ cnt + 1, cur + b });
        }

        if (cur - b > 0 && !visited[cur - b])
        {
            visited[cur - b] = true;
            q.push({ cnt + 1, cur - b });
        }

        if (cur % a == 0 && cur / a > 0 && cur / a <= m && !visited[cur / a])
        {
            visited[cur / a] = true;
            q.push({ cnt + 1, cur / a });
        }

        if (cur % b == 0 && cur / b > 0 && cur / b <= m && !visited[cur / b])
        {
            visited[cur / b] = true;
            q.push({ cnt + 1, cur / b });
        }


    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> a >> b >> n >> m;

    memset(visited, 0, sizeof(visited));

    bfs(m);

    cout << res;
}
