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

int r, c;
char arr[12][12];
vector<pair<int,int>> v;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void sink(int x, int y)
{
    int cnt = 0;
 
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || nx > r || ny < 1 || ny > c) cnt++;
        if (arr[nx][ny] == '.') cnt++;

        if (cnt >= 3)
        {
            arr[x][y] = ' ';
            return;
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (arr[i][j] == 'X')
            {
                sink(i, j);
            }
        }
    }

    int mnx = r, mxx = 1, mny = c, mxy = 1;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (arr[i][j] == 'X')
            {
                mnx = min(mnx, i);
                mxx = max(mxx, i);
                mny = min(mny, j);
                mxy = max(mxy, j);
            }
        }
    }

    for (int i = mnx; i <= mxx; i++)
    {
        for (int j = mny; j <= mxy; j++)
        {
            if (arr[i][j] == ' ') cout << '.';
            else cout << arr[i][j];
        }
        cout << '\n';
    }
}
