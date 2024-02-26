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

int n;
int dx[] = { -2,-2,0,0,2,2 };
int dy[] = { -1,1,-2,2,-1,1 };
bool visited[201][201] = { 0, };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));

    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    queue<pair<pair<int, int>,int>> q;
    q.push({{ sx,sy },0});

    while (!q.empty())
    {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if (cx == tx && cy == ty)
        {
            cout << cnt;
            return 0;
        }

        for (int i = 0; i < 6; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny])
            {
                q.push({ { nx,ny }, cnt + 1 });
                visited[nx][ny] = 1;
            }
        }
    }

    cout << -1;
}
