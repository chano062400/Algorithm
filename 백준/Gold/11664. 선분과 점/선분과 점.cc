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
using namespace std;

double GetDist(double x1, double y1, double z1, double x2, double y2, double z2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    double ax, ay, az, bx, by, bz, cx, cy, cz;
    cin >> ax >> ay >> az >> bx >> by >> bz >> cx >> cy >> cz;

    double mid1, mid2;
    for (int i = 0; i < 1000000; i++) {
        double x1 = ax + (bx - ax) / 3;
        double x2 = ax + 2 * (bx - ax) / 3;
        double y1 = ay + (by - ay) / 3;
        double y2 = ay + 2 * (by - ay) / 3;
        double z1 = az + (bz - az) / 3;
        double z2 = az + 2 * (bz - az) / 3;

        mid1 = GetDist(x1,y1,z1,cx,cy,cz);
        mid2 = GetDist(x2, y2, z2, cx, cy, cz);

        if (mid1 < mid2) {
            bx = x2;
            by = y2;
            bz = z2;
        }
        else {
            ax = x1;
            ay = y1;
            az = z1;
        }
    }

    cout.precision(11);
    cout << min(mid1, mid2);

    return 0;
};

