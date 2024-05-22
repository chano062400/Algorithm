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
 
    int h, w;
    cin >> h >> w;

    vector<int> v(w+1);

    for (int i = 1; i <= w; i++)
    {
        cin >> v[i]; 
    }

    int res = 0;
    for (int i = 2; i < w; i++)
    {
        int lmx = 0, rmx = 0;
        for (int left = 1; left < i; left++)
        {
            if(v[left] > v[i]) lmx = max(lmx, v[left]);
        }

        for (int right = i + 1; right <= w; right++)
        {
            if(v[right] > v[i]) rmx = max(rmx, v[right]);   
        }

        int height = min(lmx, rmx);
        if(lmx && rmx) res += height - v[i];
    }
    cout << res;
}
    