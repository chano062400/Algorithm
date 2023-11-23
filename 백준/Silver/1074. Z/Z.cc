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

int n, r, c, res;

void Search(int x, int y, int len)
{
    if (x == r && y == c)
    {
        cout << res;
        return;
    }

    if (x + len > r && y + len > c && r >= x && c >= y)
    {
        Search(x, y, len / 2);
        Search(x, y + len /2, len / 2);
        Search(x + len / 2 , y, len / 2);
        Search(x + len /2, y + len /2, len /2);
    }
    else
    {
        res += len * len;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
       
    cin >> n >> r >> c;
    int len = pow(2, n);

    Search(0, 0, len);

}