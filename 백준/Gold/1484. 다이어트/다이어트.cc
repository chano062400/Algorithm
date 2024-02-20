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

int g;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> g;

    vector<int> v;
    long long imagine = 1, cur = 1, sub;
    while (cur <= g)
    {
        sub = (cur * cur) - (imagine * imagine);

        if (sub < g)
        {
            cur++;
        }
        if (sub == g)
        {
            v.push_back(cur);
            cur++;
        }
        if (sub > g)
        {
            imagine++;
        }
        
    }

    if (v.empty()) cout << -1;
    else
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << '\n';
        }
    }
}
