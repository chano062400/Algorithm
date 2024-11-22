#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "memory.h"
#include <set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
using namespace std;

bool isprime(int num)
{
    if (num < 10)
    {
        if (num == 2 || num == 3 || num == 5 || num == 7) return true;
        else return false;
    }

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> primes;
    for (int i = 2; i <= n; i++)
    {
        if (isprime(i)) primes.push_back(i);
    }

    if (primes.empty())
    {
        cout << 0;
        return 0;
    }

    int start = 0, end = 0, sum = primes[0], res = 0;
    while (start <= end && end < primes.size())
    {
        if (sum == n) res++;
        if (sum <= n)
        {
            if (++end >= primes.size()) break;
            sum += primes[end];
        }
        else
        {
            sum -= primes[start++];
        }
    }
    cout << res;
}
