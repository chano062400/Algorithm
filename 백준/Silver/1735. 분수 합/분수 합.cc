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

long long gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int e = gcd(b, d);
    long long lcm = e == 1 ? b * d : e * (b / e) * (d / e);

    long long mul1 = lcm / b;
    long long mul2 = lcm / d;

    long long bunja = mul1 * a + mul2 * c;
    long long bunmo = lcm;

    while(1)
    {
        int div = gcd(bunja, bunmo);
        if (div == 1) break;
        bunja /= div;
        bunmo /= div;
    }
    cout << bunja << " " << bunmo;
}
