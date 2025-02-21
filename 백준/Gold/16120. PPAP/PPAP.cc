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

    string str;
    cin >> str;

    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'P')
        {
            if (st.empty() || st.top() == 'P')
            {
                st.push(str[i]);
            }
            else
            {
                st.pop();
                st.pop();
            }
        }
        else
        {
            if (st.size() < 2)
            {
                cout << "NP";
                return 0;
            }
            else
            {
                st.push({ str[i] });
            }
        }
    }

    if (st.size() == 1 && st.top() == 'P')
    {
        cout << "PPAP";
    }
    else
    {
        cout << "NP";
    }
}