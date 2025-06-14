 #include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include "memory.h"
#include <set>
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

struct rect 
{
    int lbx, lby, rtx, rty;
    rect(int Inlbx, int Inlby, int Inrtx, int Inrty) : lbx(Inlbx), lby(Inlby), rtx(Inrtx), rty(Inrty) {}
};

void solve(const rect& r1, const rect& r2) 
{
    int overlapX = min(r1.rtx, r2.rtx) - max(r1.lbx, r2.lbx);
    int overlapY = min(r1.rty, r2.rty) - max(r1.lby, r2.lby);

    if (overlapX > 0 && overlapY > 0) cout << "a" << '\n';
    else if ((overlapX == 0 && overlapY > 0) || (overlapX > 0 && overlapY == 0)) cout << "b" << '\n';
    else if (overlapX == 0 && overlapY == 0) cout << "c" << '\n';
    else cout << "d" << '\n';
}

int main() {
    for (int i = 0; i < 4; ++i) 
{
        int lbx1, lby1, rtx1, rty1;
        int lbx2, lby2, rtx2, rty2;
        cin >> lbx1 >> lby1 >> rtx1 >> rty1;
        cin >> lbx2 >> lby2 >> rtx2 >> rty2;

        rect r1(lbx1, lby1, rtx1, rty1);
        rect r2(lbx2, lby2, rtx2, rty2);

        solve(r1, r2);
    }
    return 0;
}