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
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    string nstr;
    cin >> nstr;

    int idx = 0;
    bool isfind = false;

    for (int i = 1; i < 30000; i++)
    {
        string str = to_string(i);

        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == nstr[idx]) idx++;

            if (idx == nstr.length())
            {
                cout << i;
                
                return 0;
            }
        }

    }
}
