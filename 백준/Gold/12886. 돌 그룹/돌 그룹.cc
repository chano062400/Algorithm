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

bool visited[1501][1501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B, C;
    cin >> A >> B >> C;
    int sum = A + B + C;
    if (sum % 3)
    {
        cout << 0;
        return 0;
    }

    queue<pair<int,int>> q;
    vector<int> v = { A, B, C };
    sort(v.begin(), v.end());
    q.push({ v[0], v[1] });

    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        int c = sum - a - b; 
        q.pop();

        if (a == b && b == c)
        {
            cout << 1;
            return 0;
        }

        if (a != b)
        {
            int na, nb, nc;
            if (a < b)
            {
                na = a * 2;
                nb = b - a;
                nc = c;
            }
            else if (a > b)
            {
                na = a - b;
                nb = b * 2;
                nc = c;
            }

            vector<int> temp = { na, nb, nc };
            sort(temp.begin(), temp.end());

            if (!visited[temp[0]][temp[1]])
            {
                q.push({ temp[0], temp[1] });
                visited[temp[0]][temp[1]] = true;
            }
        }

        if (a != c)
        {
            int na, nb, nc;
            if (a < c)
            {
                na = a * 2;
                nb = b;
                nc = c - a;
            }
            else if (a > c)
            {
                na = a - c;
                nb = b;
                nc = c * 2;
            }

            vector<int> temp = { na, nb, nc };
            sort(temp.begin(), temp.end());

            if (!visited[temp[0]][temp[1]])
            {
                q.push({ temp[0], temp[1] });
                visited[temp[0]][temp[1]] = true;
            }
        }

        if (b != c)
        {
            int na, nb, nc;
            if (b < c)
            {
                na = a;
                nb = b * 2;
                nc = c - b;
            }
            else if (b > c)
            {
                na = a;
                nb = b - c;
                nc = c * 2;
            }

            vector<int> temp = { na, nb, nc };
            sort(temp.begin(), temp.end());

            if (!visited[temp[0]][temp[1]])
            {
                q.push({ temp[0], temp[1] });
                visited[temp[0]][temp[1]] = true;
            }
        }
        
    }
    cout << 0;
}