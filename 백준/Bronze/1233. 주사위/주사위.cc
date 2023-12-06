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
    
    int num[81];
    
    memset(num, 0, sizeof(num));

    int a, b, c, mx=0;
    cin >> a >> b >> c;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int h = 1; h <= c; h++)
            {
                num[i + j + h]++;
                mx = max(mx, num[i+j+h]);
            }
        }
    }

    for (int i = 3; i <= a+b+c; i++)
    {
        if (num[i] == mx)
        {
            cout << i;
            break;  
        }
    }

}
