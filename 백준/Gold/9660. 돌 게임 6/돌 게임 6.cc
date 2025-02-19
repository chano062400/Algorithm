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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    cin >> n;

    if (n % 7 == 0 || n % 7 == 2)
    {
        cout << "CY";
    }
    else
    {
        cout << "SK";
    }
}