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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m, res =0;
    
    cin >> n >> m;
    
    vector<int> plus,minus;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num > 0) plus.push_back(num);
        else minus.push_back(num);
    }

    if(!plus.empty()) sort(plus.begin(), plus.end(), greater<int>());
    if(!minus.empty()) sort(minus.begin(), minus.end());

    int mn = !minus.empty() ? abs(minus[0]) : 0, mx = !plus.empty() ? plus[0] : 0;
    
    if (mn > mx)
    {
        while (!plus.empty())
        {
            if (plus.size() >= m)
            {
                res += plus[0] * 2;
                for (int i = 0; i < m; i++) plus.erase(plus.begin());
            }
            else
            {
                res += plus[0] * 2;
                plus.clear();
            }
        }

        res += abs(minus[0]);
        if (minus.size() >= m) for (int i = 0; i < m; i++) minus.erase(minus.begin());
        else minus.clear();

        while (!minus.empty())
        {
            if (minus.size() >= m)
            {
                res += abs(minus[0] * 2);
                for (int i = 0; i < m; i++) minus.erase(minus.begin());
            }
            else
            {
                res += abs(minus[0] * 2);
                minus.clear();
            }
        }
    }
    else
    {
        while (!minus.empty())
        {
            if (minus.size() >= m)
            {
                res += abs(minus[0] * 2);
                for (int i = 0; i < m; i++) minus.erase(minus.begin());
            }
            else
            {
                res += abs(minus[0] * 2);
                minus.clear();
            }
        }

        res += plus[0];
        if (plus.size() >= m) for (int i = 0; i < m; i++) plus.erase(plus.begin());
        else plus.clear();

        while (!plus.empty())
        {
            if (plus.size() >= m)
            {
                res += plus[0] * 2;
                for (int i = 0; i < m; i++) plus.erase(plus.begin());
            }
            else
            {
                res += plus[0] * 2;
                plus.clear();
            }
        }
    }
    
    cout << res;

}
