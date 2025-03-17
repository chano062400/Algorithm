 #include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include "memory.h"
#include <set>
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

    int n, h, t, maxheight = 1e9 + 1;
    cin >> n >> h >> t;

    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 1; i <= n; i++)
    {
        int height;
        cin >> height;
        pq.push(height);
    }

    int cnt = t;
    while (cnt > 0)
    {
        int cur = pq.top();
        if (cur <= 1 || cur < h) break;
        pq.pop();
        cur /= 2;
        cnt--;
        pq.push(cur);
    }

    if (pq.top() >= h)
    {
        cout << "NO" << '\n';
        cout << pq.top();
    }
    else
    {
        cout << "YES" << '\n';
        cout << t - cnt;
    }
}