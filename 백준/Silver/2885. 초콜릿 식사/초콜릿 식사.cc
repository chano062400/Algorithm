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

    int size = 1, res = 0, cnt = 0;

    while (n > size)
    {
        size *= 2;
    }

    res = size;

    while (n > 0)
    {
        if (n >= size) n -= size;
        else
        {
            size /= 2;
            cnt++;
        }
    }

    cout << res << " " << cnt;
}
   