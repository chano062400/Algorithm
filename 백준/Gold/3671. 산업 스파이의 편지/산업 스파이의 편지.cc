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

#define MAX 9999999
int n, prime = 0;
bool IsPrime[10000000], check[8];
vector<char> v;
set<int> Set;

void back(int len, string str)
{
    if (str.length() == len)
    {
        while (str[0] == '0')
        {
            str.erase(str.begin());
        }
        if (!str.empty() && IsPrime[stoi(str)] && Set.find(stoi(str)) == Set.end())
        {
            prime++;
            Set.insert(stoi(str));
        }
        return;
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (!check[i])
        {
            check[i] = true;
            str += v[i];
            back(len, str);
            str.pop_back();
            check[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    memset(IsPrime, 1, sizeof(IsPrime));

    IsPrime[0] = false;
    IsPrime[1] = false;
    for (int i = 2; i <= sqrt(MAX); i++)
    {
        for (int j = i * 2; j <= MAX; j += i)
        {
            IsPrime[j] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        string num;
        cin >> num;

        prime = 0;
        for (int idx = 0; idx < num.length(); idx++)
        {
            v.push_back(num[idx]);
        }

        sort(v.begin(), v.end());
        memset(check, 0, sizeof(check));

        for (int j = 1; j <= num.length(); j++)
        {
            back(j, "");
        }
        v.clear();
        Set.clear();
        cout << prime << '\n';
    }

}
