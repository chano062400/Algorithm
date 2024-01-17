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

int n, res[1001];

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    res[1] = 3;

    for (int i = 2; i <= 1000; i++)
    {
        int cnt = 0;
        for (int j = 1; j < i; j++)
        {
            if (gcd(i, j) == 1) cnt += 2;
        }
        res[i] = res[i - 1] + cnt;
    }

    cin >> n;
    while (n--)
    {
        int num; 
        cin >> num;

        cout << res[num] << '\n';
    }
 
};

