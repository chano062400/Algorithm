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

int t,w,h;
char arr[1005][1005];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<pair<int, int>> fq;
queue<pair<int, int>> sq;

void fireextend()
{
    if (fq.empty()) return;

    int size = fq.size();
    for(int i=0;i<size;i++)
    {
        int cx = fq.front().first;
        int cy = fq.front().second;
        fq.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 1 && nx <= h && ny >= 1 && ny <= w && arr[nx][ny] == '.')
            {
                arr[nx][ny] = '*';
                fq.push({ nx,ny });
            }
        }
    }
}

int bfs(int x, int y)
{
    int time = 0;

    while (!sq.empty())
    {
        time++;

        fireextend();

        int size = sq.size();
        for (int i = 0; i < size; i++)
        {
            int cx = sq.front().first;
            int cy = sq.front().second;
            sq.pop();

            if (cx == 1 || cx == h || cy == 1 || cy == w) return time;

            for (int j = 0; j < 4; j++)
            {
                int nx = cx + dx[j];
                int ny = cy + dy[j];

                if (nx >= 1 && nx <= h && ny >= 1 && ny <= w && arr[nx][ny] == '.')
                {
                    arr[nx][ny] = '@';
                    sq.push({ nx,ny });
                }
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--)
    {        
        cin >> w >> h;

        int sx = 0, sy = 0;

        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == '@')
                {
                    sq.push({ i,j });
                }
                if (arr[i][j] == '*')
                {
                    fq.push({ i,j });
                }
            }
        }

        int res = bfs(sx, sy); 
        if (res != -1) cout << res <<'\n';
        else cout << "IMPOSSIBLE" << '\n';

        memset(arr, 0, sizeof(arr));
        while (!fq.empty()) fq.pop();
        while (!sq.empty()) sq.pop();
    }
}
    