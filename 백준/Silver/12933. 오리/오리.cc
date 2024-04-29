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

char ch[] = { 'q','u','a','c','k' };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    char prev = '-';
    int duck = 0;
    vector<int> idx;

    for (int i = 0; i < str.length(); i++)
    {
        bool flag = true; 
        prev = str[i];
        if (str[i] == 'q')
        {
            idx.push_back(i);
        }

        for (int j = i+1; j < str.length(); j++)
        {
            if (prev == '-' && str[j] == 'q')
            {
                prev = 'q';
                idx.push_back(j);
            }

            if (prev == 'q' && str[j] == 'u')
            {
                prev = 'u';
                idx.push_back(j);
            }
            
            if (prev == 'u' && str[j] == 'a')
            {
                prev = 'a';
                idx.push_back(j);
            }
            
            if (prev == 'a' && str[j] == 'c')
            {
                prev = 'c';
                idx.push_back(j);
            }
            
            if (prev == 'c' && str[j] == 'k')
            {
                prev = '-';
                idx.push_back(j);

                for (auto index : idx)
                {
                    str[index] = '-';
                }
                if (flag)
                {
                    duck++;
                    flag = false;
                }
                idx.clear();
            }
        }
        idx.clear();
    }

    for (auto ch : str)
    {
        if (ch != '-')
        {
            duck = 0;
            break;
        }
    }

    if (!duck) cout << -1;
    else cout << duck;
}
   