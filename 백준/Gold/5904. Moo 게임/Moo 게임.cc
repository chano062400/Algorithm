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

int n;

void dfs(int idx, int prevlen)
{
    // 현재 moo문자 길이
    int len = prevlen * 2 + idx + 3;

    if (n <= 3)
    {
        if (n == 1)
        {
            cout << "m";
        }
        else
        {
            cout << "o";
        }
        return;
    }

    if (n <= len)
    {
        if (n <= prevlen + idx + 3)
        {// 전 moo문자 다음 문자는 m.
            if (n == prevlen + 1)
            {
                cout << "m";
            }
            else
            {
                cout << "o";
            }
            return;
        }
        else
        {
            // moo[k-1] 구간으로 돌아감.
            n -= prevlen + idx + 3;
            dfs(1, 3);
        }
    }
    else
    {
        dfs(idx + 1, len);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    dfs(1, 3);
}