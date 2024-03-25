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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    long long res = 0;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        pq.push(num);
    }
    
    long long prevsum = 0;
    for (int i = 0; i < m; i++)
    {
        long long first, second, sum;
        first = pq.top();
        pq.pop();
        second = pq.top();
        pq.pop();
        sum = first + second;
        pq.push(sum);
        pq.push(sum);

    }

    while (!pq.empty())
    {
        res += pq.top();
        pq.pop();
    }

    cout << res;
}
