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

#define MAX 1299710
bool isprime[MAX];
int t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;

    memset(isprime, 1, sizeof(isprime));

    for (int i = 2; i <= sqrt(MAX); i++)
    {
        for (int j = i * 2; j < MAX;  j += i)
        {
            isprime[j] = false;
        }
    }

    while (t--)
    {
        int num;
        cin >> num;

        int n1 = num, n2 = num;

        if (isprime[num])
        {
            cout << 0 << "\n";
            continue;
        }

        while (!isprime[n1])
            n1--;
        while (!isprime[n2])
            n2++;

        cout << n2 - n1 << '\n';
    }
}

