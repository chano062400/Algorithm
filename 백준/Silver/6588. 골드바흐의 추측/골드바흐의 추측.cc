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

bool notprime[1000001];
#define MAX 1000000

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    notprime[0] = 1;
    notprime[1] = 1;
    for (int i = 2; i <= sqrt(MAX); i++)
    {
        for (int j = i*2; j <= MAX; j+=i)
        {
            notprime[j] = 1;
        }
    }

    while (1)
    {
        int num;
        cin >> num;
        if (num == 0) break;

        for (int i = 1; i <= MAX; i++)
        {
            int res = num - i;
            if (!notprime[i] && !notprime[res])
            {
                cout << num << " = " << i << " + " << num - i << '\n';
                break;
            }
        }
    }
}
