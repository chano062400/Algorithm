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
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    long long n, res =1;
    cin >> n;

    for (long long i = 1; i <= n; i++)
    {
        res *= i;
        while(res % 10 == 0) res /= 10;
        res %= 1000000000000;
    }

    res %= 100000;
    cout << setfill('0') << setw(5) << res;
}
