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

int order[6][3] = { {9,3,1}, {9,1,3}, {3,9,1}, {3,1,9}, {1,9,3}, {1,3,9} };
int health[3] = { 0, };
int cnt[61][61][61];

struct hp
{
    int x, y, z;
};

void bfs()
{
    queue<hp> q;
    q.push({ health[0], health[1], health[2] });
    cnt[health[0]][health[1]][health[2]] = 0;
    while (!q.empty())
    {
        int cx = q.front().x;
        int cy = q.front().y;
        int cz = q.front().z;
        q.pop();

        if (cx == 0 && cy == 0 && cz == 0) return;

        for (int i = 0; i < 6; i++)
        {
            int nx = max(0, cx - order[i][0]);
            int ny = max(0, cy - order[i][1]);
            int nz = max(0, cz - order[i][2]);
            
            if (cnt[nx][ny][nz] == -1)
            {
                cnt[nx][ny][nz] = cnt[cx][cy][cz] + 1;
                q.push({ nx,ny,nz });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    

    for (int i = 0; i < n; i++)
    {
        cin >> health[i];
    }

    memset(cnt, -1, sizeof(cnt));
    bfs();
    cout << cnt[0][0][0];
}
