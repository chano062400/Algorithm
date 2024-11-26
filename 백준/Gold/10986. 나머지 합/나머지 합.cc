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
    cout.tie(nullptr);

    int n, m;
    long long res = 0;
    cin >> n >> m;
    
    vector<long long> mod(m + 1, 0);
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        sum += num;
        mod[sum % m]++;
    }
    
    for (int i = 0; i <= m; i++)
    {
        res += (mod[i] * (mod[i] - 1)) / 2;
    }

    res += mod[0];
    cout << res;
}