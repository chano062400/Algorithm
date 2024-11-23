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

    int n;
    cin >> n;
    priority_queue<int, vector<int>, less<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
 
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (i == 0)
        {
            maxheap.push(num);
        }
        else
        {
            // 1번 조건
            if (maxheap.size() > minheap.size())
            {
                minheap.push(num);
            }
            else
            {
                maxheap.push(num);
            }

            // 2번 조건
            if (minheap.top() < maxheap.top())
            {
                int mn = minheap.top();
                minheap.pop();
                int mx = maxheap.top();
                maxheap.pop();

                maxheap.push(mn);
                minheap.push(mx);
            }
        }

        cout << maxheap.top() << '\n';
    }
}
