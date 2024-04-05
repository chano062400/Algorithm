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

int n, cnt = 0, res = 0;
char arr[7][7], copy[7][7];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool visited[7][7];
vector<pair<int, int>> v;

bool canavoid(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x, ny = y;
        while (1)
        {
            nx += dx[i];
            ny += dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > n) break;
            if (arr[nx][ny] == 'O' || arr[nx][ny] == 'T') break;
            if (arr[nx][ny] == 'S') return false;
        }
    }
    return true;
}

void back(int cnt)
{
    if (cnt == 3)
    {
        for (auto& loc : v)
        {
            if (!canavoid(loc.first, loc.second)) return;
        }
        res = 1;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] == 'X')
            {
                arr[i][j] = 'O';
                back(cnt + 1);
                arr[i][j] = 'X';
            }
        }
    }
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
            if (arr[i][j] == 'T') v.push_back({ i,j });
        }
    }
    
    back(0);
    
    if (res) cout << "YES";
    else cout << "NO";
}
