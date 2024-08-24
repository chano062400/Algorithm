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

    int num = 1;
    while (1)
    {
        string str;
        cin >> str;
        if (str.find('-') != -1) break;

        stack<char> st;

        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            
            if (st.empty())
            {
                st.push(ch);
            }
            else if(ch == '{')
            {
                st.push(ch);
            }
            else if (ch == '}')
            {
                if (st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
        }

        int res = 0;
        while (!st.empty())
        {
            // top이 }인 경우 - }}
            if(st.top() == '}')
            {
                st.pop();
                st.pop();
                res++;
            }
            // top이 {인 경우 - {{, }{ 
            else if (st.top() == '{')
            {
                st.pop();
                if (st.top() == '{') res++;
                if (st.top() == '}') res += 2;
                st.pop();
            }
        }

        cout << num++ << ". " << res << '\n';
    }

}
