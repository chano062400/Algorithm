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

    int n, cnt = 0;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i])
        {
            cnt++;

            if (v[i + 1]) v[i + 1] = 0;
            else v[i + 1] = 1;

            if (v[i + 2]) v[i + 2] = 0;
            else v[i + 2] = 1;
        }
    }
    
    cout << cnt;
}
