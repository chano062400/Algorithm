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

int L, R, l =0, r =0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> L >> R;
    while (1)
    {
        if (L == 1)
        {
            r += R - 1;
            break;
        }
        else if (R == 1)
        {
            l += L - 1;
            break;
        }
        if (L < R)
        {
            r += R / L;
            R = R % L;
        }
        else if (L > R)
        {
            l += L / R;
            L = L % R;
        }
    }

    cout << l << " " << r;
}
