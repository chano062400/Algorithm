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

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    vector<int> v, lis,idx(n);
    
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    lis.push_back(v[0]);

    for (int i = 1; i < n; i++)
    {
        if (lis.back() < v[i])
        {
            lis.push_back(v[i]);
            idx[i] = lis.size() - 1;
            continue;
        }

        auto it = lower_bound(lis.begin(), lis.end(), v[i]);
        *it = v[i];
        idx[i] = it - lis.begin();
    }

    cout << lis.size() << '\n';

    stack<int> st;

    int cnt = lis.size() - 1;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (cnt == idx[i])
        {
            st.push(v[i]);
            cnt--;
        }
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
    