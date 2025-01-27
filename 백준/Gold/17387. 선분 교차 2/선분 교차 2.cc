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

typedef pair<long long, long long> pll;

long long ccw(pll p1, pll p2, pll p3)
{
    long long res = (p1.first * p2.second + p2.first * p3.second + p3.first * p1.second)
        - (p2.first * p1.second + p3.first * p2.second + p1.first * p3.second);
    // 반시계
    if (res > 0) return 1;
    // 시계
    else if (res < 0) return -1;
    // 일직선
    else return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    pll A = { x1, y1 };
    pll B = { x2, y2 };
    pll C = { x3, y3 };
    pll D = { x4, y4 };

    long long p1 = ccw(A, B, C) * ccw(A, B, D);
    long long p2 = ccw(C, D, A) * ccw(C, D, B);

    if (p1 == 0 && p2 == 0)
    {
        // first가 같다면 second 대소 비교.
        if (A > B) swap(A, B);
        if (C > D) swap(C, D);
        
        if (A <= D && B >= C) cout << 1;
        else cout << 0;
    }
    else
    {
        if (p1 <= 0 && p2 <= 0) cout << 1;
        else cout << 0;
    }
}