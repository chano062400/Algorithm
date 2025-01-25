#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "memory.h"
#include <set>
#include <unordered_set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
#include <limits.h>
#include <list>
using namespace std;

const int MAX = 987654321;
int n, m, res = MAX, visited[51][51], arr[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool check[10];
vector<pair<int, int>> pos, virus;

void copyarr()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            visited[i][j] = arr[i][j];
        }
    }
}

void spread()
{    
    copyarr();

    queue<pair<int, int>> q;
    for (auto pair : virus)
    {
        q.push({ pair.first, pair.second });
    }

    int time = 0;
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            pair<int, int> nextpos = { nx,ny };
            if (nx < 1 || nx > n || ny < 1 || ny > n) continue; // 범위 초과
            if (visited[nx][ny] != 0 || arr[nx][ny] == -1) continue; // 벽이거나, 이미 퍼트린 위치라면
            if (find(virus.begin(), virus.end(), nextpos) != virus.end()) continue; // 초기 바이러스라면
            visited[nx][ny] = visited[cx][cy] + 1;
            q.push({ nx,ny });
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pair<int, int> pair = { i,j };
            if (visited[i][j] == 0 && (find(virus.begin(), virus.end(), pair) == virus.end())) return; // 바이러스가 퍼지지 않은 위치가 있다면
            time = max(time, visited[i][j]);
        }
    }

    res = min(res, time);
}

void back(int index, int cnt)
{
    if (cnt == m)
    {
        spread();
        return;
    }

    for (int i = index; i < pos.size(); i++)
    {
        if (!check[i])
        {
            check[i] = true;
            virus.push_back({ pos[i].first, pos[i].second });
            back(i + 1, cnt + 1);
            virus.pop_back();
            check[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                arr[i][j] = -1;
            }
            if (arr[i][j] == 2)
            {
                pos.push_back({ i,j });
                arr[i][j] = 0;
            }
        }
    }

    back(0, 0);

    res == MAX ? cout << -1 : cout << res;
}