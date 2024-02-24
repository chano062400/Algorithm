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

int s, t;
set<long long> SET;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s >> t;
    if (s == t)
    {
        cout << 0;
        return 0;
    }

    queue<pair<long long,string>> q;
    q.push({ s,""});

    while (!q.empty())
    {
        long long cur = q.front().first;
        string str = q.front().second;
        q.pop();

        if (cur == t)
        {
            cout << str;
            return 0;
        }

        if (1 <= cur * cur  && cur * cur <= 1000000000)
        {
            if (SET.find(cur * cur) == SET.end())
            {
                SET.insert(cur * cur);
                q.push({ cur * cur, str + "*" });
            }
        }
        
        if (1 <= cur + cur  && cur + cur <= 1000000000)
        {
            if (SET.find(cur + cur) == SET.end())
            {
                SET.insert(cur + cur);
                q.push({ cur + cur, str + "+" });
            }
        }

        if (cur > 0)
        {
            if (SET.find(cur / cur) == SET.end())
            {
                SET.insert(cur / cur);
                q.push({ cur / cur, str + "/" });
            }
        }

    }

    cout << -1;
}
