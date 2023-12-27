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

int arr[6][6];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
map<string, bool> num;

void bfs(int x, int y, string str)
{
    queue<pair<string,pair<int, int>>> q;
    q.push({ str ,{x,y}});

    while (!q.empty())
    {
        string cstr = q.front().first;
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            string nstr = to_string(arr[nx][ny]) + cstr;

            if (nx >= 1 && nx <= 5 && ny >= 1 && ny <= 5)
            {
                if(nstr.length() < 6) q.push({ nstr,{nx,ny } });
                if (nstr.length() == 6)
                {
                    if (num.find(nstr) == num.end()) num[nstr] = 1;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            bfs(i, j, to_string(arr[i][j]));
        }
    }

    cout << num.size();
}
