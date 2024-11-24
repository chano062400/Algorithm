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

    int n, k, c;
    cin >> n >> k;

    vector<pair<int, int>> jew;
    for (int i = 0; i < n; i++)
    {
        int m, v;
        cin >> m >> v;
        jew.push_back({ m, v });
    }

    vector<int> bag;
    for (int i = 0; i < k; i++)
    {
        cin >> c;
        bag.push_back(c);
    }

    sort(jew.begin(), jew.end());
    sort(bag.begin(), bag.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
    int idx = 0;
    long long res = 0;
    for (int i = 0; i < bag.size(); i++)
    {
        while (idx < jew.size() && jew[idx].first <= bag[i])
        {
            pq.push({ jew[idx].second, jew[idx].first });
            idx++;
        }

        if (!pq.empty())
        {
            res += pq.top().first;
            pq.pop();
        }
    }
    cout << res;
}
