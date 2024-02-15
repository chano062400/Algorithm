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

long long a, b;

long long gcd(long long a, long long b)
{
    if (b == 0) return a;
    
    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> a >> b;

    long long cnt = gcd(a, b);

    for (int i = 1; i <= cnt; i++)
    {
        cout << 1;
    }
};

