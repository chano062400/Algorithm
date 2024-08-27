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

    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    string res;
    while (n != 0)
    {
        if (n % -2 == 0)
        {
            res += "0";
            n /= -2;
        }
        else
        {
            res += "1";
            n = (n - 1) / -2;
        }
    }

    reverse(res.begin(), res.end());

    cout << res;
}

