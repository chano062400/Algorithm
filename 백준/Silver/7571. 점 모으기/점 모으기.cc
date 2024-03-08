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

    int n, m, res = 0;
    cin >> n >> m;

    vector<int> x,y;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    // 중간값
    int midx = x[m / 2]; 
    int midy = y[m / 2];

    for (int i = 0; i < m; i++)
    {
        res += abs(x[i] - midx) + abs(y[i] - midy);
    }

    cout << res;
}
