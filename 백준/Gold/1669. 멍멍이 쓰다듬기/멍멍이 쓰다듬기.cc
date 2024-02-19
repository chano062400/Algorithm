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

long long x, y;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> x >> y;

    long long key = 0;
    long long dif = y - x;
    
    if (dif == 0)
    {
        cout << 0;
        return 0;
    }

    for (long long i = 0; ; i++)
    {
        if (i * i >= dif)
        {
            key = i;
            break;
        }
    }

    if (key * key - key  < dif)
    {
        cout << key * 2 - 1;
    }
    else
    {
        cout << key * 2 - 2;
    }
};

