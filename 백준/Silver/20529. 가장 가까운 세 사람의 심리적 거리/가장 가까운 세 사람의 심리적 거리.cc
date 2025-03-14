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

int calcdist(string str1, string str2)
{
    int dist = 0;
    for (int i = 0; i < 4; i++)
    {
        if (str1[i] != str2[i]) dist++;
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;

        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        if (n > 32)
        {
            cout << 0 << '\n';
            continue;
        }

        int res = 100;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    res = min(res, calcdist(v[i], v[j]) + calcdist(v[j], v[k]) + calcdist(v[i], v[k]));
                }
            }
        }

        cout << res << '\n';
    }
}
