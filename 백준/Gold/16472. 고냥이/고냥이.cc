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

int alpha[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string str;
    cin >> str;

    int s = 0, e = 0, cnt = 0, len = 0, res = 0;
    while (s <= e && e < str.length())
    {
        int startidx = str[s] - 'a';
        int endidx = str[e] - 'a';

        if (alpha[endidx] == 0)
        {
            if (cnt < n)
            {
                alpha[endidx]++;
                cnt++;
                len++;
                e++;
            }
            else
            {
                if (--alpha[startidx] == 0)
                {
                    cnt--;
                }
                len--;
                s++;
            }
        }
        else
        {

            alpha[endidx]++;
            len++;
            e++;
        }
        
        res = max(res, len);
    }

    cout << res;
}