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

int arr[129][129];
int n, b=0, w=0, res=0;

void Search(int x, int y, int len)
{
    bool dif = false;
    int color = arr[x][y];
    for (int i = x; i < x + len; i++)
    {
        for (int j = y; j < y + len; j++)
        {
            if (arr[i][j] != color)
            {
                dif = true;
                break;
            }
        }
        if (dif)
        {
            break;
        }
    }

    if (!dif)
    {
        if (color == 1) b++;
        else w++;
        return;
    }

    Search(x, y, len / 2);
    Search(x, y + len /2 , len / 2);
    Search(x + len /2, y, len /2);
    Search(x + len /2, y + len /2, len /2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    Search(1, 1, n);

    cout << w << '\n' << b;
}