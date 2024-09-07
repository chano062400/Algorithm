#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stack>
#include <regex>
#include <map>
#include <cstdlib>
#include <list>
#include <sstream>
#include <bitset>
#include <set>
#include <unordered_map>
#include <numeric>
#include <memory>
using namespace std;

#define MOD 1000000007
typedef long long ll;
int t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        priority_queue<ll, vector<ll>, greater<ll>> pq;

        for (int i = 0; i < n; i++) 
        {
            ll num;
            cin >> num;
            pq.push(num);
        }

        ll res = 1;
        while (pq.size() > 1)
        {
            ll n1 = pq.top();
            pq.pop();
            ll n2 = pq.top();
            pq.pop();

            ll mul = n1 * n2; 

            res = res * (mul % MOD) % MOD; 
            pq.push(mul);
        }

        cout << res << '\n';
    }
}

