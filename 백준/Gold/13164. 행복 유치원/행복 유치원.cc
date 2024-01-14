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
using namespace std;

int n, k;
long long res = 0;
vector<long long> v, dif;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        v.push_back(h);
    }

    for (int i = 0; i < n - 1; i++)
    {
        dif.push_back(v[i + 1] - v[i]);
    }

    sort(dif.begin(), dif.end());

    for (int i = 0; i < n - k; i++)
    {
        res += dif[i];
    }
    
    cout << res;
};

