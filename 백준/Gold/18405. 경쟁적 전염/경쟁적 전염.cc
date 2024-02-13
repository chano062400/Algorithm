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

int n, k;
int arr[201][201] = { 0, };
bool visited[201][201];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
vector<pair<int, int>> v[1001];

void spread(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = 1;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !visited[nx][ny] && arr[nx][ny] == 0)
            {
                visited[nx][ny] = 1;
                arr[nx][ny] = arr[cx][cy];
                v[arr[cx][cy]].push_back({ nx,ny });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] != 0) v[arr[i][j]].push_back({ i,j });
        }
    }
    int s, tx, ty;
    cin >> s >> tx >> ty;

    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int size = v[j].size();
            for (int h = 0; h < size; h++)
            {
                spread(v[j][0].first, v[j][0].second);
                v[j].erase(v[j].begin());
            }
        }
        memset(visited, 0, sizeof(visited));
    }

    cout << arr[tx][ty];
};

