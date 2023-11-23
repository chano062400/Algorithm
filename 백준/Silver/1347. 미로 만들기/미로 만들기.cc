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
using namespace std;

char arr[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
       
    cin >> n;

    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            arr[i][j] = '#';
        }
    }

    int Rot = 0, cx = 25, cy = 25, mxx = 0, mnx = 25, mxy = 0, mny = 25;
    arr[cx][cy] = '.';

    while(n--)
    {
        char ch;
        cin >> ch;

        if (ch == 'L')
        {
            Rot += 1;
            if (Rot > 3) Rot = 0;
        }
        if (ch == 'R')
        {
            Rot -= 1;
            if (Rot < 0) Rot = 3;
        }
        if (ch == 'F')
        {
            int nx = cx + dx[Rot];
            int ny = cy + dy[Rot];
            arr[nx][ny] = '.';
            cx = nx;
            cy = ny;
        }

        mxx = max(mxx, cx);
        mnx = min(mnx, cx);
        mxy = max(mxy, cy);
        mny = min(mny, cy);
    }

    for (int i = mnx; i <= mxx; i++)
    {
        for (int j = mny; j <= mxy; j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }
}