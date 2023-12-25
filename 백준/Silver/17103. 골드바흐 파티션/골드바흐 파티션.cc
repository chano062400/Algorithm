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

int t;
bool prime[1000001];
vector<int> v, cnt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    memset(prime, 0, sizeof(prime));
    cnt.resize(v.size());

    for (int i = 2; i <= sqrt(1000000); i++)
    {
        for (int j = i * 2; j <= 1000000; j += i)
        {
            prime[j] = 1;
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 2; j <= v[i] / 2; j++)
        {
            if (!prime[j] && !prime[v[i] - j])
            {
                cnt[i]++;
            }
        }
    }
   
    for (auto n : cnt) cout << n << '\n';
}
