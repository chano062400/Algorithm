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
using namespace std;

int getState(int v1, int v2, int v3, int v4)
{
    // v1-v2 영역과 v3-v4 영역이 떨어져있음
    if (v2 < v3 || v4 < v1) return 0;
    // 한 지점이 맞닿아 있음
    else if (v2 == v3 || v4 == v1) return 1;
    // 겹쳐져 있음
    return 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    long long x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    
    int x = getState(x1, x2, x3, x4);
    int y = getState(y1, y2, y3, y4);

    if (x == 0 || y == 0)
        cout << "NULL";
    else if (x == 1)
    {
        if (y == 1) cout << "POINT";
        if (y == 2) cout << "LINE";
    }
    else if (x == 2)
    {
        if (y == 1) cout << "LINE";
        if (y == 2) cout << "FACE";
    }
}
