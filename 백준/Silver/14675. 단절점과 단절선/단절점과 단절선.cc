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

int in[100001], out[100001], n, q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<pair<int, int>> v;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });

        in[a]++;
        out[a]++;
        in[b]++;
        out[b]++;
    }

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int t, k;
        cin >> t >> k;

        if (t == 1)
        {
            if (in[k] == 1 && out[k]) cout << "no" << '\n';
            else cout << "yes" << '\n';
        }
        else
        {
            if (in[v[k].first] == 1 && in[v[k].second] == 1 && out[v[k].first] == 1 && out[v[k].second] == 1) cout << "no" << '\n';
            else cout << "yes" << '\n';
        }
    }
}