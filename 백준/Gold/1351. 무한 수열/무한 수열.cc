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

long long n, p, q;
unordered_map<long long, long long> num;

long long dfs(long long cur)
{
    if (num.find(cur) != num.end()) return num[cur];

    return num[cur] = dfs(cur / p) + dfs(cur / q);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> p >> q;
    num[0] = 1;

    dfs(n);

    cout << num[n];
}