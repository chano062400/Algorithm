#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "memory.h"
#include <set>
#include <unordered_set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
#include <limits.h>
#include <list>
using namespace std;

long long a, b, res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b;
    long long sqrtb = floor(sqrt(b));
    vector<bool> isprime(sqrtb + 1, 1);

    isprime[0] = isprime[1] = false;
    for (long long i = 2; i <= sqrtb; i++)
    {
        if (isprime[i])
        {
            for (long long j = i * i; j <= sqrtb; j += i)
            {
                isprime[j] = false;
            }
        }
    }
    
    for (long long i = 2; i <= sqrtb; i++)
    {
        if (!isprime[i]) continue;
        for (long long j = i * i; j <= b; j *= i)
        {
            if (j < a) continue;
            res++;
            if (j > b / i) break;
        }
    }

    cout << res;
}