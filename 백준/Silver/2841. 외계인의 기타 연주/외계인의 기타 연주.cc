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
#include <numeric>
#include <memory>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, p, cnt = 0;
    stack<int> st[7];

    cin >> n >> p;
    
    for (int i = 0; i < n; i++)
    {
        int line, fret;
        cin >> line >> fret;
        if (st[line].empty() || st[line].top() < fret)
        {
            st[line].push(fret);
            cnt++;
        }
        
        else if (st[line].top() == fret) continue;

        else if (st[line].top() > fret)
        {
            while (st[line].top() > fret)
            {
                st[line].pop();
                cnt++;

                if (st[line].empty()) break;
            }
            
            if (!st[line].empty() && st[line].top() == fret) continue;

            st[line].push(fret);
            cnt++;
        }
    }

    cout << cnt;
}
