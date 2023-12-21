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
using namespace std;

long long n, res= 1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = n; i >= 1; i--)
    {
        res *= i;
        res %= 10000000;
        while (res % 10 == 0) res /= 10;
    }

    cout << res % 10;

}
