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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<bool> isprime(n + 1, 1);
    vector<int> primes;

    if (n < 2)
    {
        cout << 0;
        return 0;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        for (int j = i * 2; j <= n; j += i)
        {
            isprime[j] = false;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (isprime[i])
        {
            primes.push_back(i);
        }
    }

    int start = 0, end = 0, sum = primes[0], res = 0;
    while(start <= end && end < primes.size())
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
