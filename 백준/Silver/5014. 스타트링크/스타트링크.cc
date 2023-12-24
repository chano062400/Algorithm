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

int F, S, G, U, D, res = 987654321;
bool visited[1000001];

void bfs(int start)
{
    queue<pair<int, int>> q;
    q.push({ start, 0 });

    while (!q.empty())
    {
        int cur = q.front().first;
        int curcnt = q.front().second;
        q.pop();

        if (cur == G) 
        {
            res = curcnt; 
            return;
        }

        if (cur + U <= F && !visited[cur + U])
        {
            q.push({ cur + U , curcnt + 1 });
            visited[cur + U] = 1;
        }
        if (cur - D >= 1 && !visited[cur - D])
        {
            q.push({ cur - D , curcnt + 1 });
            visited[cur - D] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    

    cin >> F >> S >> G >> U >> D;

    bfs(S);

    if (res == 987654321) cout << "use the stairs" << '\n';
    else cout << res;
}
