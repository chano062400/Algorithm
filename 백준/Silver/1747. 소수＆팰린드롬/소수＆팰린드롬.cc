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

#define MAX 2000000
bool isprime[MAX+1];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    memset(isprime, 1, sizeof(isprime));

    isprime[1] = false;
    for (int i = 2; i < sqrt(MAX); i++)
    {
        for (int j = i * 2; j <= MAX; j += i)
        {
            isprime[j] = false;
        }
    }

    for (int i = n; i <= MAX; i++)
    {
        if (!isprime[i]) continue;
        bool pel = true;
        string str = to_string(i);
        int len = str.length() - 1;
        for (int j = 0; j <= len / 2; j++)
        {
            if (str[j] - '0' != str[len - j] - '0')
            {
                pel = false;
                break;
            }
        }
        if (pel)
        {
            cout << i;
            return 0;
        }
    }
}
    