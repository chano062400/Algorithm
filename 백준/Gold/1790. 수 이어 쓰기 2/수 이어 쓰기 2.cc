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
using namespace std;

int n, k, p = 0, res = -1;
long long num = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    int tempk = k;
    for (int i = 0; i <= 8; i++)
    {
        long long tmpnum = (pow(10, i) * 9) * (i + 1); // 각 자릿수들의 수 개수. 한 자릿수는 9, 두 자릿수는 90 ... 

        if (tmpnum >= k)
        {
            int div = ceil(double(tempk) / double((i+1))), idx = tempk % (i+1);
            num += div;
            if (n >= num)
            {
                string str = to_string(num);
                idx += i;
                cout << str[idx % (i + 1)];
                break;
            }
            else
            {
                cout << -1;
                break;  
            }
        }
        else
        {
            tempk -= tmpnum;
            num += (pow(10, i) * 9);
        }
    }

}
