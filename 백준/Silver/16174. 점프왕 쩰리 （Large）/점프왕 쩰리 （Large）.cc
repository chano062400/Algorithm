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

int n, arr[65][65];
int dx[] = { 1,0 };
int dy[] = { 0,1 };
bool visited[65][65] = { 0 };

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = 1;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        int move = arr[cx][cy];
        q.pop();

        if (cx == n && cy == n)
        {
            cout << "HaruHaru" << '\n';
            return;
        }

        for (int i = 0; i < 2; i++)
        {
            int nx = cx + dx[i] * move;
            int ny = cy + dy[i] * move;

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !visited[nx][ny])
            {
                visited[nx][ny] = 1;
                q.push({ nx,ny });
            }
        }
    }

    cout << "Hing" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    bfs(1, 1);
}
