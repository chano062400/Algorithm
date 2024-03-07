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
    
    int n, m, idx = 0, res =0;
    
    cin >> n >> m;
    
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {   
        cin >> v[i];
        if (v[i] < 0) idx++;
    }

    sort(v.begin(), v.end());

    // 양수
    for (int i = n - 1; i >= idx; i -= m)
    {
        res += v[i] * 2;
    }

    // 음수
    for (int i = 0; i < idx; i += m)
    {
        res += abs(v[i] * 2);
    }

    res -= max(abs(v[0]), v[n - 1]);

    cout << res;
}
