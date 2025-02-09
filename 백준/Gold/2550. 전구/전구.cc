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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> v(n + 1, 0), lis, idx(n + 1, 0);
    // SwitchToLight
    map<int, int> STL;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        STL[num] = i;
    }

    lis.push_back(STL[v[1]]);
    for (int i = 2; i <= n; i++)
    {
        if (lis.back() < STL[v[i]])
        {
            lis.push_back(STL[v[i]]);
            idx[i] = lis.size() - 1;
        }
        else
        {
            auto it = lower_bound(lis.begin(), lis.end(), STL[v[i]]);
            *it = STL[v[i]];
            idx[i] = it - lis.begin();
        }
    }

    stack<int> st;

    int cnt = lis.size() - 1;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (cnt == idx[i])
        {
            st.push(i);
            cnt--;
        }
    }

    cout << lis.size() << '\n';

    vector<int> res;
    while (!st.empty())
    {
        res.push_back(v[st.top()]);
        st.pop();
    }

    sort(res.begin(), res.end());

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}