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

    int n, k;
    long long res = 0;
    cin >> n >> k; 
    vector<int> v(21);
    queue<int> q;
    for (int i = 0; i < n; i++)
    { 
        string str;
        cin >> str;
        
        res += v[str.length()];

        if (q.size() >= k)
        {
            v[q.front()]--;
            q.pop();
        }

        v[str.length()]++;
        q.push(str.length());
    }
    
    cout << res;
}